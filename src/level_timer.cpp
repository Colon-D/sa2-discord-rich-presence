#include "sa2_discord_rich_presence/level_timer.h"
#include "sa2_discord_rich_presence/chao.h"

/// whether time is paused or not
bool time_paused() {
	if (CurrentLevel == LevelIDs::LevelIDs_ChaoWorld) {
		const auto chao_area = static_cast<::chao_area>(CurrentChaoArea);
		switch (chao_area) {
		case chao_area::chao_race: {
			if (
				current_chao_race_timer == chao_race_timer{}
				|| !chao_race_not_finished
			) {
				return true;
			}
			break;
		}
		case chao_area::chao_karate:
		case chao_area::chao_karate_2p: {
			if (
				in_chao_karate_match()
				&& chao_karate->unknown[4] != 2
			) {
				return true;
			}
			break;
		}
		default:
			break;
		}
	}
	// todo: what are TimeStopped and TimerStopped?
	return
		GameState == GameStates::GameStates_Pause
		|| (TimeStopped != 0)
		|| (TimerStopped != 0);
}
/// gets current time elapsed in level
std::optional<frames> time_elapsed_in_level() {
	using namespace std::chrono;
	if (
		CurrentLevel != LevelIDs::LevelIDs_ChaoWorld
	) {
		// if in multiplayer, return nullopt
		if (TwoPlayerMode != 0) {
			return {};
		}
		auto time_elapsed =
			minutes{ +TimerMinutes }
			+ seconds{ +TimerSeconds }
			+ frames{ +TimerFrames };

		// on kart race, it takes around 7 seconds for the race to begin
		// (4 for zooming in, 3 for countdown)
		// (timer also doesn't stop at end of kart race, I could find the value
		// for the kart race timer, along with whether the race had ended, but
		// I don't care)
		if (CurrentLevel == LevelIDs::LevelIDs_KartRace) {
			time_elapsed -= seconds{ 7 };
		}
		return time_elapsed;
	}

	const auto chao_area = static_cast<::chao_area>(CurrentChaoArea);
	switch (chao_area) {
	case chao_area::chao_race:
		return current_chao_race_timer.duration();
	case chao_area::chao_karate:
	case chao_area::chao_karate_2p:
		if (
			in_chao_karate_match()
		) {
			const auto chao_karate_time_elapsed = 90s - seconds{ chao_karate->time };
			return chao_karate_time_elapsed;
		}
		break;
	default:
		break;
	}
	return {};
}
/// gets time point at start of level
std::optional<time_point> start_of_level() {
	using namespace std::chrono;
	// if we can get time elapsed
	if (
		const auto time_elapsed = time_elapsed_in_level()
	) {
		// minus elapsed time from now
		const auto now = time_point_cast<frames>(system_clock::now());
		return now - *time_elapsed;
	}
	return {};
}
/// gets time point at end of level, if applicable
std::optional<time_point> end_of_level() {
	if (const auto limit = current_level_time_limit()) {
		if (const auto start = start_of_level()) {
			return *start + *limit;
		}
	}
	return {};
}

std::optional<frames> level_time_limit(
	const LevelIDs  level_id,
	const int       mission_number,
	const chao_area chao_area
) {
	// ideally I would find a memory address that has these values but I can't.
	// these are manually typed, some may be wrong, mods could change them.
	// source: each level's page on https://info.sonicretro.org
	// note: 2p levels are NOT included, as I do not think they are not listed
	// on sonic retro, and I can't be bothered timing each level to find out.
	using namespace std::chrono_literals;
	std::optional<frames> time_limit{};
	switch (level_id) {
	case LevelIDs::LevelIDs_GreenForest:
		switch (mission_number) {
		case 1:
			return 8min;
		case 4:
			return 4min;
		}
		break;
	case LevelIDs::LevelIDs_WhiteJungle:
		switch (mission_number) {
		case 1:
			return 10min;
		case 4:
			return 3min;
		}
		break;
	case LevelIDs::LevelIDs_PumpkinHill:
		if (mission_number == 4) {
			return 3min;
		}
		break;
	case LevelIDs::LevelIDs_SkyRail:
		if (mission_number == 4) {
			return 2min;
		}
		break;
	case LevelIDs::LevelIDs_AquaticMine:
		if (mission_number == 4) {
			return 3min + 30s;
		}
		break;
	case LevelIDs::LevelIDs_SecurityHall:
		switch (mission_number) {
		case 1:
			return 5min;
		case 4:
			return 3min + 30s;
		}
		break;
	case LevelIDs::LevelIDs_PrisonLane:
		if (mission_number == 4) {
			return 3min;
		}
		break;
	case LevelIDs::LevelIDs_MetalHarbor:
		if (mission_number == 4) {
			return 2min;
		}
		break;
	case LevelIDs::LevelIDs_IronGate:
		if (mission_number == 4) {
			return 4min;
		}
		break;
	case LevelIDs::LevelIDs_WeaponsBed:
		if (mission_number == 4) {
			return 2min + 45s;
		}
		break;
	case LevelIDs::LevelIDs_CityEscape:
		if (mission_number == 4) {
			return 3min;
		}
		break;
	case LevelIDs::LevelIDs_RadicalHighway:
		if (mission_number == 4) {
			return 3min;
		}
		break;
	case LevelIDs::LevelIDs_WildCanyon:
		if (mission_number == 4) {
			return 2min;
		}
		break;
	case LevelIDs::LevelIDs_MissionStreet:
		if (mission_number == 4) {
			return 5min;
		}
		break;
	case LevelIDs::LevelIDs_DryLagoon:
		if (mission_number == 4) {
			return 3min + 30s;
		}
		break;
	case LevelIDs::LevelIDs_SandOcean:
		if (mission_number == 4) {
			return 4min;
		}
		break;
	case LevelIDs::LevelIDs_CrazyGadget:
		if (mission_number == 4) {
			return 5min;
		}
		break;
	case LevelIDs::LevelIDs_HiddenBase:
		if (mission_number == 4) {
			return 3min + 30s;
		}
		break;
	case LevelIDs::LevelIDs_EternalEngine:
		if (mission_number == 4) {
			return 5min;
		}
		break;
	case LevelIDs::LevelIDs_DeathChamber:
		if (mission_number == 4) {
			return 5min;
		}
		break;
	case LevelIDs::LevelIDs_EggQuarters:
		if (mission_number == 4) {
			return 3min;
		}
		break;
	case LevelIDs::LevelIDs_LostColony:
		if (mission_number == 4) {
			return 3min + 30s;
		}
		break;
	case LevelIDs::LevelIDs_PyramidCave:
		if (mission_number == 4) {
			return 4min;
		}
		break;
	case LevelIDs::LevelIDs_FinalRush:
		if (mission_number == 4) {
			return 5min;
		}
		break;
	case LevelIDs::LevelIDs_MeteorHerd:
		if (mission_number == 4) {
			return 4min + 30s;
		}
		break;
	case LevelIDs::LevelIDs_CannonsCoreS:
	case LevelIDs::LevelIDs_CannonsCoreE:
	case LevelIDs::LevelIDs_CannonsCoreT:
	case LevelIDs::LevelIDs_CannonsCoreR:
	case LevelIDs::LevelIDs_CannonsCoreK:
		if (mission_number == 4) {
			return 7min;
		}
		break;
	case LevelIDs::LevelIDs_FinalChase:
		if (mission_number == 4) {
			return 5min + 30s;
		}
		break;
	case LevelIDs::LevelIDs_CosmicWall:
		if (mission_number == 4) {
			return 8min;
		}
		break;
	case LevelIDs::LevelIDs_MadSpace:
		if (mission_number == 4) {
			return 4min + 30s;
		}
		break;
	case LevelIDs::LevelIDs_FinalHazard:
		return 5min;
	case LevelIDs::LevelIDs_ChaoWorld:
		switch (chao_area) {
		case chao_area::chao_karate:
		case chao_area::chao_karate_2p:
			using namespace std::chrono;
			if (chao_karate != nullptr) {
				return 1min + 30s;
			}
		default:
			break;
		}
		break;
	default:
		break;
	}
	return {};
}

std::optional<frames> current_level_time_limit() {
	return level_time_limit(
		static_cast<LevelIDs>(CurrentLevel),
		+MissionNum + 1,
		current_chao_area
	);
}

frames chao_race_timer::duration() const {
	return
		std::chrono::minutes{ minutes }
		+ std::chrono::seconds{ seconds }
		+ ::frames{ frames };
}

bool operator==(const chao_race_timer& lhs, const chao_race_timer& rhs) {
	return lhs.minutes == rhs.minutes
		&& lhs.seconds == rhs.seconds
		&& lhs.frames == rhs.frames;
}
