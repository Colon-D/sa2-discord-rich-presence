#include "sa2_discord_rich_presence/modding.h"
#include <IniFile.hpp>
#include <filesystem>

std::unordered_map<std::string, std::unique_ptr<IniFile>> mods{};
std::vector<std::string> mod_order{};
std::unordered_set<std::string> codes;
std::vector<std::string> code_order{};

void read_mods_and_codes() {
	const IniFile ini_file{ "mods/SA2ModLoader.ini" };
	const auto& group = *ini_file.getGroup("");
	// mod loader supports up to 999 mods
	// https://github.com/X-Hax/sa2-mod-loader/blob/923faec46b34ca374ef888ceef94a882c1bd7be4/SA2ModLoader/dllmain.cpp#L1310
	for (int mod{ 1 }; mod <= 999; ++mod) {
		// check if ini_file has the key "ModX" where X is the mod number
		const auto key = "Mod" + std::to_string(mod);
		if (!group.hasKey(key)) {
			break;
		}
		// get the value of this key, which is the mod directory
		const auto mod_directory = group.getString(key);
		// open the mod ini file inside the mod directory
		IniFile mod_ini_file{ "mods/" + mod_directory + "/mod.ini" };
		// read the name of the mod from the mod ini file
		const auto mod_name = mod_ini_file.getString("", "Name");
		// check if mod's config file exists
		const auto mod_config_path = "mods/" + mod_directory + "/config.ini";
		std::unique_ptr<IniFile> mod_config{ nullptr };
		if (std::filesystem::exists(mod_config_path)) {
			// mod's config.ini file is only opened in constructor
			mod_config = std::make_unique<IniFile>(mod_config_path);
		}
		// insert mod's name and mod's config.ini file into mods map and vector
		mods.insert({
			mod_name,
			std::move(mod_config)
		});
		mod_order.push_back(mod_name);
	}
	// codes are loaded differently, perhaps there is no upper limit set?
	//
	// whilst codes CAN skip numbers, it seems Saving is required to updated
	// Codes.dat, which is how the codes get loaded. Saving makes each code
	// number contiguous, solving this problem.
	//
	// I believe it is possible for someone to update their ini file outside of
	// the mod manager, thus making this ini file not equal to Codes.dat.
	// I do not know a solution to this problem.
	for (int code{ 1 };; ++code) {
		// check if ini_file has the key "CodeX" where X is the code number
		const auto key = "Code" + std::to_string(code);
		if (!group.hasKey(key)) {
			break;
		}
		// get the value of this key, which is the code's name
		const auto code_name = group.getString(key);
		// insert code's name into codes set
		codes.insert(code_name);
		code_order.push_back(code_name);
	}
}
