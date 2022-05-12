#include "sa2_discord_rich_presence/player.h"
#include "sa2_discord_rich_presence/modding.h"

std::size_t current_player(const std::size_t player) {
	if (CurrentLevel == LevelIDs::LevelIDs_FinalHazard) {
		const char final_hazard_player{
			*reinterpret_cast<const char*>(0x174B00B)
		};
		return +final_hazard_player;
	}
	return player;
}

std::string current_player_state(const std::size_t player) {
	const bool show_lives{
		TwoPlayerMode == 0
		&& CurrentLevel != LevelIDs::LevelIDs_KartRace
	};

	auto state = "Rings: " + std::to_string(RingCount[current_player(player)]);
	if (show_lives) {
		state += ", Lives: " + std::to_string(Life_Count[player]);
	}
	return state;
}
