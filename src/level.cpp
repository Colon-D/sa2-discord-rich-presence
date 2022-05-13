#include "sa2_discord_rich_presence/level.h"
#include "sa2_discord_rich_presence/asset_name.h"
#include "sa2_discord_rich_presence/chao.h"
#include "sa2_discord_rich_presence/character.h"
#include "sa2_discord_rich_presence/events.h"
#include "sa2_discord_rich_presence/level_timer.h"
#include "sa2_discord_rich_presence/player.h"
#include "sa2_discord_rich_presence/timer.h"
#include <array>
#include <cassert>
#include <format>
#include <string>

std::unordered_map<LevelIDs, name_and_image_asset_boolean> level_names{
	{ LevelIDs::LevelIDs_BasicTest,       { "Basic Test"                , true } },
	{ LevelIDs::LevelIDs_KnucklesTest,    { "Knuckles Test"             , true } },
	{ LevelIDs::LevelIDs_SonicTest,       { "Sonic Test"                , true } },
	{ LevelIDs::LevelIDs_GreenForest,     { "Green Forest"              , true } },
	{ LevelIDs::LevelIDs_WhiteJungle,     { "White Jungle"              , true } },
	{ LevelIDs::LevelIDs_PumpkinHill,     { "Pumpkin Hill"              , true } },
	{ LevelIDs::LevelIDs_SkyRail,         { "Sky Rail"                  , true } },
	{ LevelIDs::LevelIDs_AquaticMine,     { "Aquatic Mine"              , true } },
	{ LevelIDs::LevelIDs_SecurityHall,    { "Security Hall"             , true } },
	{ LevelIDs::LevelIDs_PrisonLane,      { "Prison Lane"               , true } },
	{ LevelIDs::LevelIDs_MetalHarbor,     { "Metal Harbor"              , true } },
	{ LevelIDs::LevelIDs_IronGate,        { "Iron Gate"                 , true } },
	{ LevelIDs::LevelIDs_WeaponsBed,      { "Weapons Bed"               , true } },
	{ LevelIDs::LevelIDs_CityEscape,      { "City Escape"               , true } },
	{ LevelIDs::LevelIDs_RadicalHighway,  { "Radical Highway"           , true } },
	{ LevelIDs::LevelIDs_WeaponsBed2P,    { "Weapons Bed 2P"            , true } },
	{ LevelIDs::LevelIDs_WildCanyon,      { "Wild Canyon"               , true } },
	{ LevelIDs::LevelIDs_MissionStreet,   { "Mission Street"            , true } },
	{ LevelIDs::LevelIDs_DryLagoon,       { "Dry Lagoon"                , true } },
	{ LevelIDs::LevelIDs_SonicVsShadow1,  { "Sonic vs. Shadow"          , true } },
	{ LevelIDs::LevelIDs_TailsVsEggman1,  { "Tails vs. Dr. Eggman"      , true } },
	{ LevelIDs::LevelIDs_SandOcean,       { "Sand Ocean"                , true } },
	{ LevelIDs::LevelIDs_CrazyGadget,     { "Crazy Gadget"              , true } },
	{ LevelIDs::LevelIDs_HiddenBase,      { "Hidden Base"               , true } },
	{ LevelIDs::LevelIDs_EternalEngine,   { "Eternal Engine"            , true } },
	{ LevelIDs::LevelIDs_DeathChamber,    { "Death Chamber"             , true } },
	{ LevelIDs::LevelIDs_EggQuarters,     { "Egg Quarters"              , true } },
	{ LevelIDs::LevelIDs_LostColony,      { "Lost Colony"               , true } },
	{ LevelIDs::LevelIDs_PyramidCave,     { "Pyramid Cave"              , true } },
	{ LevelIDs::LevelIDs_TailsVsEggman2,  { "Tails vs. Dr. Eggman 2"    , true } },
	{ LevelIDs::LevelIDs_FinalRush,       { "Final Rush"                , true } },
	{ LevelIDs::LevelIDs_GreenHill,       { "Green Hill"                , true } },
	{ LevelIDs::LevelIDs_MeteorHerd,      { "Meteor Herd"               , true } },
	{ LevelIDs::LevelIDs_KnucklesVsRouge, { "Knuckles vs. Rouge"        , true } },
	{ LevelIDs::LevelIDs_CannonsCoreS,    { "Cannons Core (Sonic)"      , true } },
	{ LevelIDs::LevelIDs_CannonsCoreE,    { "Cannons Core (Dr. Eggman)" , true } },
	{ LevelIDs::LevelIDs_CannonsCoreT,    { "Cannons Core (Tails)"      , true } },
	{ LevelIDs::LevelIDs_CannonsCoreR,    { "Cannons Core (Rouge)"      , true } },
	{ LevelIDs::LevelIDs_CannonsCoreK,    { "Cannons Core (Knuckles)"   , true } },
	{ LevelIDs::LevelIDs_MissionStreet2P, { "Mission Street 2P"         , true } },
	{ LevelIDs::LevelIDs_FinalChase,      { "Final Chase"               , true } },
	{ LevelIDs::LevelIDs_WildCanyon2P,    { "Wild Canyon 2P"            , true } },
	{ LevelIDs::LevelIDs_SonicVsShadow2,  { "Sonic vs. Shadow 2"        , true } },
	{ LevelIDs::LevelIDs_CosmicWall,      { "Cosmic Wall"               , true } },
	{ LevelIDs::LevelIDs_MadSpace,        { "Mad Space"                 , true } },
	{ LevelIDs::LevelIDs_SandOcean2P,     { "Sand Ocean 2P"             , true } },
	{ LevelIDs::LevelIDs_DryLagoon2P,     { "Dry Lagoon 2P"             , true } },
	{ LevelIDs::LevelIDs_PyramidRace,     { "Pyramid Race"              , true } },
	{ LevelIDs::LevelIDs_HiddenBase2P,    { "Hidden Base 2P"            , true } },
	{ LevelIDs::LevelIDs_PoolQuest,       { "Pool Quest"                , true } },
	{ LevelIDs::LevelIDs_PlanetQuest,     { "Planet Quest"              , true } },
	{ LevelIDs::LevelIDs_DeckRace,        { "Deck Race"                 , true } },
	{ LevelIDs::LevelIDs_DowntownRace,    { "Downtown Race"             , true } },
	{ LevelIDs::LevelIDs_CosmicWall2P,    { "Cosmic Wall 2P"            , true } },
	{ LevelIDs::LevelIDs_GrindRace,       { "Grind Race"                , true } },
	{ LevelIDs::LevelIDs_LostColony2P,    { "Lost Colony 2P"            , true } },
	{ LevelIDs::LevelIDs_EternalEngine2P, { "Eternal Engine 2P"         , true } },
	{ LevelIDs::LevelIDs_MetalHarbor2P,   { "Metal Harbor 2P"           , true } },
	{ LevelIDs::LevelIDs_IronGate2P,      { "Iron Gate 2P"              , true } },
	{ LevelIDs::LevelIDs_DeathChamber2P,  { "Death Chamber 2P"          , true } },
	{ LevelIDs::LevelIDs_BigFoot,         { "F-6t Big Foot"             , true } },
	{ LevelIDs::LevelIDs_HotShot,         { "B-3x Hot Shot"             , true } },
	{ LevelIDs::LevelIDs_FlyingDog,       { "R-1/A Flying Dog"          , true } },
	{ LevelIDs::LevelIDs_KingBoomBoo,     { "King Boom Boo"             , true } },
	{ LevelIDs::LevelIDs_EggGolemS,       { "The Egg Golem (Sonic)"     , true } },
	{ LevelIDs::LevelIDs_Biolizard,       { "The Biolizard"             , true } },
	{ LevelIDs::LevelIDs_FinalHazard,     { "The Finalhazard"           , true } },
	{ LevelIDs::LevelIDs_EggGolemE,       { "The Egg Golem (Dr. Eggman)", true } }
};

std::optional<std::string> level_name(const LevelIDs level_id) {
	if (
		const auto level_name_and_image_asset_boolean =
			::level_name_and_image_asset_boolean(level_id)
	) {
		return level_name_and_image_asset_boolean->name;
	}
	return {};
}

std::optional<name_and_image_asset_boolean> level_name_and_image_asset_boolean(
	const LevelIDs level_id
) {
	if (
		const auto it = level_names.find(level_id);
		it != level_names.end()
	) {
		return it->second;
	}
	return {};
}

void set_level_name(
	const LevelIDs     level_id,
	const std::string& name,
	const bool         has_image_asset
) {
	const auto level_name = level_names.find(level_id);
	assert(level_name != level_names.end());
	level_name->second = { name, has_image_asset };
}

name_and_image_asset_boolean route_101_name{ "Route 101", true };
name_and_image_asset_boolean route_280_name{ "Route 280", true };

std::string route_101_280_name(const bool route_280) {
	return route_101_280_name_and_asset_image_boolean(route_280).name;
}

name_and_image_asset_boolean route_101_280_name_and_asset_image_boolean(
	const bool route_280
) {
	return route_280 ? route_280_name : route_101_name;
}

void set_route_101_280_name(
	const bool         route_280,
	const std::string& name,
	const bool         has_image_asset
) {
	(route_280 ? route_280_name : route_101_name) = { name, has_image_asset };
}

std::optional<std::string> kart_race_course_name(
	const std::uint32_t kart_race_course
) {
	std::string kart_race_course_string{};
	switch (kart_race_course) {
	case 0:
		kart_race_course_string = "Beginner";
		break;
	case 1:
		kart_race_course_string = "Standard";
		break;
	case 2:
		kart_race_course_string = "Expert";
		break;
	default:
		return {};
	}
	return "Kart Race (" + kart_race_course_string + ')';
}

std::optional<std::string> current_level_name() {
	if (
		const auto current_level_name_and_image_asset_boolean =
			::current_level_name_and_image_asset_boolean()
	) {
		return current_level_name_and_image_asset_boolean->name;
	}
	return {};
}

std::optional<name_and_image_asset_boolean>
current_level_name_and_image_asset_boolean() {
	const auto current_level = static_cast<LevelIDs>(CurrentLevel);
	switch (current_level) {
	case LevelIDs::LevelIDs_Route101280:
		return route_101_280_name_and_asset_image_boolean(
			CurrentCharacter == +Characters::Characters_Rouge
		);
	case LevelIDs::LevelIDs_KartRace:
		if (
			const auto kart_race_course_name =
				::kart_race_course_name(current_kart_race_course)
		) {
			return { { *kart_race_course_name, true } };
		}
		return {};
	case LevelIDs::LevelIDs_ChaoWorld:
		return chao_area_name_and_image_asset_boolean(current_chao_area);
	default:
		return level_name_and_image_asset_boolean(current_level);
	}
}

std::optional<std::string> boss_name(
	const LevelIDs level_id, const Characters character
) {
	switch (level_id) {
	case LevelIDs::LevelIDs_SonicVsShadow1:
	case LevelIDs::LevelIDs_TailsVsEggman1:
	case LevelIDs::LevelIDs_TailsVsEggman2:
	case LevelIDs::LevelIDs_KnucklesVsRouge:
	case LevelIDs::LevelIDs_SonicVsShadow2:
		return character_name(opposite_polarity(character));
	case LevelIDs::LevelIDs_BigFoot:
	case LevelIDs::LevelIDs_HotShot:
	case LevelIDs::LevelIDs_FlyingDog:
	case LevelIDs::LevelIDs_KingBoomBoo:
		return level_name(level_id);
	case LevelIDs::LevelIDs_EggGolemS:
	case LevelIDs::LevelIDs_EggGolemE:
	case LevelIDs::LevelIDs_Biolizard:
	case LevelIDs::LevelIDs_FinalHazard: {
		if (auto boss_name = level_name(level_id)) {
			// convert first character in boss name ('T' of "The") to lowercase
			(*boss_name)[0] = static_cast<char>(std::tolower((*boss_name)[0]));
			return *boss_name;
		}
		return {};
	}
	default:
		// not fighting anyone
		return {};
	}
}
std::optional<std::string> current_boss_name() {
	return boss_name(
		static_cast<LevelIDs>(CurrentLevel),
		static_cast<Characters>(CurrentCharacter)
	);
}

std::size_t players() {
	return static_cast<std::size_t>(TwoPlayerMode == 0 ? 1 : 2);
}

void update_level_small_image(discord::rich_presence& rpc) {
	const auto players = ::players();
	// if playing in 1p, use 1p's character as small_image_key
	if (players == 1) {
		rpc.small_image_key =
			asset_name(character_name(current_character(0)));
	}
	// else if playing multiplayer and kart racing,
	// use kart symbol as small_image_key
	else if (CurrentLevel == LevelIDs::LevelIDs_KartRace) {
		rpc.small_image_key = "kart_race";
	}
	// else if playing regular multiplayer,
	// use character class in common as small_image_key
	else {
		const std::array char_class {
			character_class(current_character(0)),
			character_class(current_character(1))
		};

		// if both characters are the same class (and not other),
		if (
			char_class[0] == char_class[1]
			&& char_class[0] != character_class::other
		) {
			// set small image key to character class battle name
			rpc.small_image_key =
				asset_name(character_class_battle_name(char_class[0]));
		}
		// if characters are different classes or other
		else {
			// set small image key to unknown battle
			rpc.small_image_key = "unknown_battle";
		}
	}
	// set small image text to character names
	for (std::size_t player{ 0 }; player < players; ++player) {
		rpc.small_image_text += character_name(current_character(player));
		// if not last player, add vertical bar seperator
		if (player < players - 1) {
			rpc.small_image_text += " | ";
		}
	}
}

void update_level_large_image(discord::rich_presence& rpc) {
	if (
		const auto level_name_and_image_asset_boolean =
			::current_level_name_and_image_asset_boolean()
	) {
		if (level_name_and_image_asset_boolean->has_image_asset) {
			rpc.large_image_key =
				asset_name(level_name_and_image_asset_boolean->name);
		}
		else {
			rpc.large_image_key = "unknown";
		}
		rpc.large_image_text = level_name_and_image_asset_boolean->name;
		// if on a mission that is not 1, append it
		const auto mission_number = +MissionNum + 1;
		if (mission_number > 1) {
			rpc.large_image_text +=
				", Mission: " + std::to_string(mission_number);
		}
	}
	else {
		rpc.large_image_key = "unknown";
		rpc.large_image_text =
			"Unknown Level: " + std::to_string(+CurrentLevel);
	}
}

void update_level_details(discord::rich_presence& rpc) {
	// set details to lives (if not kart race nor 2p) and rings

	// set details
	const auto players = ::players();
	for (std::size_t player{ 0 }; player < players; ++player) {
		rpc.details += current_player_state(player);
		// if not last player, add vertical bar seperator
		if (player < players - 1) {
			rpc.details += " | ";
		}
	}
}

void update_level_state(discord::rich_presence& rpc) {
	// I would love to display the boss, but I can't because the state gets
	// cluttered when paused. I can't display it in details because then it is
	// cluttered when the game is unpaused as the state is empty!
	// It can be derived from the level name alongside the current character.
	constexpr bool display_boss{ false };
	if constexpr (display_boss) {
		// display who we are fighting, if anyone
		if (const auto boss_name = ::current_boss_name()) {
			rpc.state = "Fighting " + *boss_name;
		}
	}
	// timer stopped, display paused time
	if (
		time_paused()
	) {
		if (const auto elapsed = time_elapsed_in_level()) {
			if (!rpc.state.empty()) {
				rpc.state += ", ";
			}
			using namespace std::chrono;
			if (const auto limit = current_level_time_limit()) {
				const auto left = duration_cast<seconds>(*limit - *elapsed);
				rpc.state += std::format("{:%M:%S}", left) + " left";
			}
			else {
				const auto elapsed_seconds = duration_cast<seconds>(*elapsed);
				rpc.state +=
					std::format("{:%M:%S}", elapsed_seconds) + " elapsed";
			}
		}
	}
	// paused
	if (GameState == GameStates::GameStates_Pause) {
		if (!rpc.state.empty()) {
			rpc.state += ", ";
		}
		rpc.state += "Paused";
	}
}

void update_level_timestamp(discord::rich_presence& rpc) {
	// if paused, clock will be stopped
	if (
		time_paused()
	) {
		return;
	}
	// set rpc
	if (const auto start = start_of_level()) {
		rpc.start_timestamp = *start;
	}
	// if there is a time limit, set end_timestamp
	if (const auto end = end_of_level()) {
		rpc.end_timestamp = *end;
	}
}

void update_level_rpc(discord::rich_presence& rpc) {
	// if not playing the level or paused, then level
	// value will probably not be set so return
	if (
		GameState != GameStates::GameStates_Ingame &&
		GameState != GameStates::GameStates_Pause
	) {
		return;
	}
	update_level_small_image(rpc);
	update_level_large_image(rpc);
	update_level_state(rpc);
	// chao world rpc!
	if (CurrentLevel == LevelIDs::LevelIDs_ChaoWorld) {
		update_chao_world_rpc(rpc);
	}
	else {
		// if an event is playing, set rpc to watching it and return
		if (MainCharObj1[0]->Action == Actions::Action_CutsceneAnimation) {
			rpc.details = "Watching a Gameplay Event";
			if (const auto gameplay_event_name = ::gameplay_event_name(current_gameplay_event)) {
				rpc.state = *gameplay_event_name;
			}
			else {
				// display unknown gameplay event
				rpc.state = "Unknown Gameplay Event "
					+ std::to_string(
						static_cast<int>(current_gameplay_event)
					);
			}
			return;
		}
		update_level_details(rpc);
	}
	update_level_timestamp(rpc);
}
