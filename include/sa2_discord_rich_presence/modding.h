#pragma once
#include <IniFile.hpp>
#include <SA2ModLoader.h>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <unordered_map>
#include <unordered_set>

#undef min
#undef max

/// key: mod's name, value: mod's config.ini file, if it exists.
/// ideally the value should be of type std::optional<IniFile>, but this
/// crashes on destuction of the value.
extern std::unordered_map<std::string, std::unique_ptr<IniFile>> mods;
/// mod names, in the order that they load in
extern std::vector<std::string> mod_order;
/// key: code's name
extern std::unordered_set<std::string> codes;
/// code names, in the order that they (probably) load in
extern std::vector<std::string> code_order;
/// reads enabled mods and codes into mods, mod_order, codes and code_order
void read_mods_and_codes();

using addr = std::uint32_t;

template <typename data_type>
auto* arr(const addr address) {
	return reinterpret_cast<data_type*>(address);
}

template<typename data_type>
auto& ref(const addr address) {
	return *reinterpret_cast<data_type*>(address);
}

struct stru {
	addr address{};

	template<typename data_type>
	[[nodiscard]] auto& field(const addr offset) const {
		return ref<data_type>(address + offset);
	}
};

/// this uses the mod loader's GenerateUsercallHook function.
/// I encountered what appears to be a bug, at least on my PC. When replacing
/// a call, this writes a jump instead of another call. This is because
/// dereferencing a char pointer seems to allow values above 0xFF. I believe
/// chars are stored as integers for efficiency, and since the address is next
/// to the char in memory without padding, part of the address corrupts the
/// check for whether this is replacing a call or not.
/// I solved this by adding a 0xFF bitmask to the check.
template <typename T, typename... TArgs>
constexpr void generate_usercall_hook_fixed(
	const T& func, int ret, intptr_t address, TArgs... args
) {
	constexpr std::uint8_t    call_op{ 0xE8 };
	const std::uint8_t* const addr{ reinterpret_cast<std::uint8_t*>(address) };
	const bool                call{ (*addr & 0xFF) == call_op };
	GenerateUsercallHook(
		const_cast<void*>(reinterpret_cast<const void*>(func)),
		ret,
		address,
		args...
	);
	if (call) {
		WriteData(addr, call_op);
	}
}

/// casts write_addr and func_addr to void* and calls WriteJump
template <typename write_addr_t, typename func_addr_t>
void write_jump(const write_addr_t& write_addr, const func_addr_t& func_addr) {
	WriteJump(
		const_cast<void*>(reinterpret_cast<const void*>(write_addr)),
		const_cast<void*>(reinterpret_cast<const void*>(func_addr))
	);
}

/// casts write_addr and func_addr to void* and calls WriteCall
template <typename write_addr_t, typename func_addr_t>
void write_call(const write_addr_t& write_addr, const func_addr_t& func_addr) {
	WriteCall(
		const_cast<void*>(reinterpret_cast<const void*>(write_addr)),
		const_cast<void*>(reinterpret_cast<const void*>(func_addr))
	);
}

/// casts write_addr to void* and calls WriteData
template <std::size_t count, typename write_addr_t>
void write_data(const write_addr_t& write_addr, const char data) {
	WriteData<count>(
		const_cast<void*>(reinterpret_cast<const void*>(write_addr)), data
	);
}
