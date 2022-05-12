#pragma once
#include "sa2_discord_rich_presence/modding.h"
#include "sa2_discord_rich_presence/chao.h"
#include "sa2_discord_rich_presence/discord_rich_presence.h"
#include <cstddef>
#include <optional>
#include <string>

// this is sooo messy... I am not sure of a better way to rewrite this.
// perhaps to have a big enum class not related to level ids, and inside this
// would be each level id, each kart race, each chao area...

/// get name from level IDs, not including:
/// - LevelIDs::LevelIDs_Route101280
/// - LevelIDs::LevelIDs_KartRace
/// - LevelIDs::LevelIDs_ChaoWorld
///
/// instead use route_101_280_name(), kart_race_course_name() or
/// chao_area_name() for those level IDs.
std::optional<std::string> level_name(LevelIDs level_id);

/// get name and image asset boolean from level IDs, not including:
/// - LevelIDs::LevelIDs_Route101280
/// - LevelIDs::LevelIDs_KartRace
/// - LevelIDs::LevelIDs_ChaoWorld
///
/// instead use route_101_280_name_and_image_asset_boolean(),
/// kart_race_course_name() or
/// chao_area_name_and_image_asset_boolean() for those level IDs.
///
/// Kart Race nor Route 101/Route 280 have image asset booleans
std::optional<name_and_image_asset_boolean> level_name_and_image_asset_boolean(
	LevelIDs level_id
);

/// set name from level IDs, not including:
/// - LevelIDs::LevelIDs_Route101280
/// - LevelIDs::LevelIDs_KartRace
/// - LevelIDs::LevelIDs_ChaoWorld
///
/// for a chao area, use set_chao_area_name()
/// for route 101/route 280, use set_route_101_280_name()
/// all other kart levels are currently unchangable, as it is not needed now.
///
/// \param has_image_asset does the replacement level name have a Discord asset
/// image uploaded? Unless you are me, it do not. Setting this to false will
/// display the "unknown" Discord asset, which is preferable to an invalid one.
void set_level_name(
	LevelIDs level_id, const std::string& name, bool has_image_asset = false
);

/// returns route 101/route 280's name
std::string route_101_280_name(bool route_280);
/// returns route 101/route 280's name and image asset boolean
name_and_image_asset_boolean route_101_280_name_and_asset_image_boolean(
	bool route_280
);
/// sets route 101/route 280's name
/// \param has_image_asset does the replacement level name have a Discord asset
/// image uploaded? Unless you are me, it do not. Setting this to false will
/// display the "unknown" Discord asset, which is preferable to an invalid one.
void set_route_101_280_name(
	bool route_280, const std::string& name, bool has_image_asset = false
);

/// returns kart race course name
std::optional<std::string> kart_race_course_name(
	std::uint32_t kart_race_course
);

static auto& current_kart_race_course = ref<std::uint32_t>(0x174B070);

/// returns current level name, including:
/// - LevelIDs::LevelIDs_Route101280
/// - LevelIDs::LevelIDs_KartRace
/// - LevelIDs::LevelIDs_ChaoWorld
std::optional<std::string> current_level_name();

/// returns current level name and image asset boolean, including:
/// - LevelIDs::LevelIDs_Route101280
/// - LevelIDs::LevelIDs_KartRace
/// - LevelIDs::LevelIDs_ChaoWorld
std::optional<name_and_image_asset_boolean>
	current_level_name_and_image_asset_boolean();

/// returns boss name, if applicable
/// \param character needed for character fights
std::optional<std::string> boss_name(LevelIDs level_id, Characters character);
std::optional<std::string> current_boss_name();

/// character(s)
void update_level_small_image(discord::rich_presence& rpc);
/// level/chao area
void update_level_large_image(discord::rich_presence& rpc);
/// rings and lives
void update_level_details(discord::rich_presence& rpc);
/// who we are fighting, whether paused or not, and time if paused
void update_level_state(discord::rich_presence& rpc);
/// if not in multiplayer, timer.
/// I know multiplayer can have a 4 minute timer, but it does not seem to
/// use the same timer as the other levels, and I can't find it
void update_level_timestamp(discord::rich_presence& rpc);

/// updates rpc depending on gamestate, chao world, or gameplay event
void update_level_rpc(discord::rich_presence& rpc);
