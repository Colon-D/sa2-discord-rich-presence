#pragma once
#include <string>

/// all the menus I could find, similar to SA2Enums.h's Menus, but I did not
/// know that enum existed when I made this. Oh well, some we have some extra
/// values like story_summary and options_file_select, that's about it.
enum class menu {
	title_screen, // press start
	main, // 1p play, 2p battle, extra, options, etc
	story_select,
	stage_select,
	// either only accessable without the Battle DLC, or through
	// SPEEPSHighway's Menu Overhaul. I have only tested the latter.
	two_player_battle_action,
	story_summary,
	options,
	sound_test = 8,
	file_select,
	kart_race,
	boss_attack = 0xC,
	// disabled on PC, accessable through SPEEPSHighway's Menu Overhaul
	tutorial,
	emblem_results = 0xF,
	two_player_battle,
	controls = 0x15,
	bonus_video,
	how_to_play,
	options_file_select
};

std::string menu_name(menu menu);

std::string current_menu_name();

/// similar to SA2Enums.h's GameMode, but with demo added and
/// menu renamed from advertise
enum class gamemode {
	initialize,
	start_level = 4,
	level,
	reset_level,
	load_event,
	event,
	load_demo,
	demo,
	load_story = 12,
	load_menu,
	menu,
	load_ending,
	ending,
	load_emblem_screen,
	emblem_screen,
	load_logos = 21,
	logos
};
