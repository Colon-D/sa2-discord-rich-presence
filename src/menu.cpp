#include "sa2_discord_rich_presence/menu.h"
#include "sa2_discord_rich_presence/modding.h"

std::string menu_name(const menu menu) {
	switch (menu) {
	case menu::title_screen:
		return "Title Screen";
	case menu::main:
		return "Main";
	case menu::story_select:
		return "Story Select";
	case menu::stage_select:
		return "Stage Select";
	case menu::two_player_battle_action:
		return "2P Battle: Action";
	case menu::story_summary:
		return "Story Summary";
	case menu::options:
		return "Options";
	case menu::sound_test:
		return "Sound Test";
	case menu::file_select:
		return "File Select";
	case menu::kart_race:
		return "Kart Race";
	case menu::boss_attack:
		return "Boss Attack";
	case menu::tutorial:
		return "Tutorial";
	case menu::emblem_results:
		return "Emblem Results";
	case menu::two_player_battle:
		return "2P Battle";
	case menu::controls:
		return "Controls";
	case menu::bonus_video:
		return "Bonus Video";
	case menu::how_to_play:
		return "How To Play";
	case menu::options_file_select:
		return "Options: File Select";
	}
	return "Unknown";
}

std::string current_menu_name() {
	return menu_name(static_cast<menu>(CurrentMenu));
}
