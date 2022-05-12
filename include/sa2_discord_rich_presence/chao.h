#pragma once
#include "sa2_discord_rich_presence/discord_rich_presence.h"
#include "sa2_discord_rich_presence/modding.h"
#include <array>
#include <optional>
#include <string>
#include <unordered_map>

/// similar to SA2Enums.h's ChaoArea enum,
/// but with the change of lobby from value 0 to value 7 (0 seemed wrong),
/// changed name of neutral garden to chao garden (as it is called ingame),
/// changed chao name machine to departure machine,
/// added chao prefix to most values (to match ingame)
/// and addition of 2p race entrance and 2p karate
enum class chao_area {
	chao_lobby_alternative, // ChaoArea states this is the lobby.
	                        // this is not true from what I have tested
	chao_garden,
	hero_garden,
	dark_garden,
	chao_race,
	chao_race_entrance, // this is also referred to as Chao Race Entry ingame
	chao_kindergarten,
	chao_lobby,
	chao_race_entrance_2p,
	chao_stadium,
	chao_karate,
	chao_karate_2p,
	chao_departure_machine,
};

static auto& current_chao_area =
	*reinterpret_cast<chao_area*>(&CurrentChaoArea);

/// \param chao_race_course [0, 12]
/// beginner: [0, 3], jewel: [4, 9], challenge: 10, hero: 11, dark: 12
/// \param chao_race_level
/// beginner: [0, 3) (difficulty), jewel: [0, 5) (difficulty),
/// challenge: [0, 12), hero: [0, 4), dark: [0, 4)
/// \param newer_challenge_race_mod use challenge names from the Newer
/// Challenge Race mod
std::string chao_race_course_name(
	std::uint8_t chao_race_course,
	std::uint8_t chao_race_level,
	bool         newer_challenge_race_mod = false
);

/// [0, 12],
/// beginner: [0, 3], jewel: [4, 9], challenge: 10, hero: 11, dark: 12
static auto& current_chao_race_course = ref<std::uint8_t>(0x1A0FBD4);
/// beginner: [0, 3) (difficulty), jewel: [0, 5) (difficulty),
/// challenge: [0, 12), hero: [0, 4), dark: [0, 4)
static auto& current_chao_race_level  = ref<std::uint8_t>(0x1A0FBD5);

/// \param chao_karate_level [0, 4]
/// \param chao_karate_busters_tournament_mod use level names from the Chao
/// Karate: Buster's Tournament mod
/// \param chao_karate_busters_tournament_extra_mode use level names from Chao
/// Karate: Buster's Tournament's Extra Mode
/// \param chao_karate_busters_tournament_encore_mode append (Encore) to the
/// name
std::string chao_karate_level_name(
	std::uint8_t        chao_karate_level,
	bool                chao_karate_busters_tournament_mod = false,
	std::optional<bool> chao_karate_busters_tournament_extra_mode  = {},
	std::optional<bool> chao_karate_busters_tournament_encore_mode = {}
);

static auto& chao_karate_busters_tournament_extra_mode = ref<bool>(0x13134CB);

struct name_and_image_asset_boolean {
	std::string name{};
	bool has_image_asset{ false };
};

/// \param chao_race_course needed for the course name of a Chao Race
/// \param chao_race_level needed for the course name of a Chao Race
std::string chao_area_name(
	chao_area                   chao_area,
	std::optional<std::uint8_t> chao_race_course = {},
	std::optional<std::uint8_t> chao_race_level = {}
);

/// \param chao_race_course needed for the course name of a Chao Race
/// \param chao_race_level needed for the course name of a Chao Race
name_and_image_asset_boolean chao_area_name_and_image_asset_boolean(
	chao_area                   chao_area,
	std::optional<std::uint8_t> chao_race_course = {},
	std::optional<std::uint8_t> chao_race_level = {}
);

/// set name from chao_area, not including:
/// - chao_area::chao_lobby_alternative (uses chao_area::chao_lobby)
/// - chao_area::chao_race_entrance_2p  (uses chao_area::chao_race_entrance)
/// - chao_area::chao_karate_2p         (uses chao_area::chao_karate)
///
/// Chao World Extended, Chao Karate: Buster's Tournament, and Newer Challenge
/// Race are hardcoded. Rewriting dozens of functions to use use some other
/// design for potential future mods is too much work for me right now.
///
/// \param has_image_asset does the replacement level name have a Discord asset
/// image uploaded? Unless you are me, it do not. Setting this to false will
/// display the "unknown" Discord asset, which is preferable to an invalid one.
void set_chao_area_name(
	chao_area chao_area, const std::string& name, bool has_image_asset = false
);

/// exception thrown when a chao name is tried to be
/// decoded whilst ini::chao_names is false
class chao_name_decoding_not_allowed_exception : public std::exception {
public:
	[[nodiscard]] const char* what() const noexcept override;
};

/// decodes chao char to a utf8 encoded std::string
/// \exception chao_name_decoding_not_allowed_exception when
/// ini::chao_names is false
std::string decode_chao_char(char encoded_chao_char, bool cpu_name = false);

/// decodes chao name from a chao string to a utf8 encoded std::string
/// \param cpu_name if true, bypasses disabled allow_decoding_of_chao_names
/// \exception chao_name_decoding_not_allowed_exception when
/// ini::chao_names is false
std::string decode_chao_name(
	const char* encoded_chao_name,
	std::size_t maximum_length = 7,
	bool        cpu_name = false
);

/// decodes chao name from chao data to a utf8 encoded std::string.
/// If using the Chao World Extended mod, this will use the extended name.
/// \param cpu_name if true, bypasses disabled allow_decoding_of_chao_names
/// \exception chao_name_decoding_not_allowed_exception when
/// ini::chao_names is false
std::string decode_chao_name(
	const ChaoDataBase& chao_data,
	bool                cpu_name = false
);

/// number of player chao (in your gardens, not cpu) in race.
/// either 8 (with CWE), 2 or 1.
std::size_t player_chao_in_chao_race();

static auto& chao_race_not_finished = ref<bool>(0x133AE14);

/// data2 of chao karate chao (karate_chao_exec).
/// chao_karate prefix is needed, as this data is only related to
/// chao karate chao. not regular chao, not the chao karate in general, but
/// data related to the chao participating in the chao karate.
/// get it? no? well luckily I am the only one reading this, haha - unless 😳?
struct chao_karate_chao_data2 {
	std::array<std::uint8_t, 0x10> unknown{};
	/// nullptr for cpu chao
	ChaoData* player_chao{};
	std::array<std::uint8_t, 0x24> unknown2{};
	/// [0, 1000]
	float zeal{};
	float health{};
	std::uint32_t unknown3{};
	float max_health{};
	/// counts up until idk then they attack
	float next_attack_timer{};
	// perhaps longer, bytes between start of both instance of this is 0x108
};

struct chao_karate {
	/// unknown[4] seems to equal 2 in match when timer is counting down
	std::array<std::uint8_t, 7> unknown{};
	/// [0, 5]
	std::uint8_t matches_won{};
	std::array<std::uint8_t, 2> unknown2{};
	/// [0, 4) -> Beginner, Standard, Expert, Super
	std::uint8_t level{};
	std::uint8_t unknown3{};
	/// counts down from 90 to 0
	std::uint16_t time{};
	std::array<std::uint8_t, 2> unknown4{};
	/// karate_chao_exec, nullptr out of match
	std::array<ObjectMaster*, 2> chao_karate_chao_object{};

	/// static_cast<chao_karate_chao_data2*>(this->chao_karate_chao_object[chao_index]->Data2.Undefined)
	chao_karate_chao_data2* chao_karate_chao_data2(std::size_t chao_index);

	// below don't seem to be used
	[[deprecated("not used ingame, use chao_karate_chao_data2(chao_index)->player_chao instead")]]
	std::array<ChaoData*, 2> player_chao{}; /// nullptr for cpu chao
	[[deprecated("not used ingame, use chao_karate_chao_data2(chao_index)->health instead")]]
	float* lhs_health{};
	[[deprecated("not used ingame, use chao_karate_chao_data2(chao_index)->Data2)->health instead")]]
	float* rhs_health{};
	[[deprecated("not used ingame, use chao_karate_chao_data2(chao_index)->Data2)->zeal instead")]]
	float* lhs_zeal{};
	[[deprecated("not used ingame, use chao_karate_chao_data2(chao_index)->Data2)->zeal instead")]]
	float* rhs_zeal{};
	// perhaps longer
};

static auto& chao_karate = ref<struct chao_karate*>(0x1A5D148);

bool in_chao_karate_match();

void update_chao_race_rpc(discord::rich_presence& rpc);
void update_chao_karate_rpc(discord::rich_presence& rpc);
/// if chao world is not loaded, clears rpc and returns,
/// else sets small_image if doing 2p chao racing or 2p chao karate,
/// also sets large_image_key to hero_race or dark_race if applicable,
/// appends chao race course name to large image text if applicable
void update_chao_world_rpc(discord::rich_presence& rpc);
