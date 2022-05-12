#pragma once
#include "sa2_discord_rich_presence/chao.h"
#include "sa2_discord_rich_presence/modding.h"
#include "sa2_discord_rich_presence/timer.h"
#include <optional>

/// a combination of level and timer functions, to avoid cyclic dependencies
/// and so I do not need to decide whether the functions should have went in
/// the level or timer files.

/// whether time is paused or not
bool time_paused();
/// gets current time elapsed in level, if somewhat applicable
std::optional<frames> time_elapsed_in_level();
/// gets time point at start of level, if somewhat applicable
std::optional<time_point> start_of_level();
/// gets time point at end of level, if somewhat applicable
std::optional<time_point> end_of_level();

/// returns time limit for a singleplayer level
/// \param mission_number [1, 5]
std::optional<frames> level_time_limit(
	LevelIDs level_id, int mission_number, chao_area chao_area
);
/// returns current time limit
std::optional<frames> current_level_time_limit();

// chao

struct chao_race_timer {
	std::uint8_t minutes{};
	std::uint8_t seconds{};
	std::uint8_t frames{};

	::frames duration() const;
};
bool operator==(const chao_race_timer& lhs, const chao_race_timer& rhs);
static auto& current_chao_race_timer = ref<struct chao_race_timer>(0x1A0FBD0);
