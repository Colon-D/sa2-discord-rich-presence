#pragma once
#include "sa2_discord_rich_presence/modding.h"
#include <string>
#include <optional>

// Based off of SA2 Mod Loader's event names:
// https://github.com/X-Hax/sa2-mod-loader/blob/854dacb678206eeae22e6f21455d56935289ec9a/SA2ModManager/MainForm.cs#L1399
// and for events not in SA2 Mod Loader, Sonic Retro's event names:
// https://info.sonicretro.org/SCHG:Sonic_Adventure_2/Event_List and
// the former describes when the event happens,
// the latter describes what happens in the event.
// I have combined the worst of both to produce this abomination.
enum class event {
	// hero
	hero_story_intro                                       = 0,
	sonic_meets_shadow                                     = 2,
	knuckles_meets_rouge                                   = 3,
	tails_flies_to_prison_island                           = 4,
	tails_vs_dr_eggman_aftermath                           = 5,
	sonic_escapes_from_his_cell                            = 6,
	sonic_and_friends_witness_the_arks_power               = 11,
	wheres_dr_eggman                                       = 14,
	sonic_and_tails_intercept_dr_eggmans_video             = 15,
	locate_dr_eggmans_pyramid_base                         = 16,
	knuckles_begins_looking_for_the_gate_keys              = 17,
	dr_eggman_ambushes_sonic_inside_the_base               = 19,
	tails_explains_his_plans_to_destroy_the_eclipse_cannon = 21,
	sonic_receives_a_call_for_ransom_from_dr_eggman        = 22,
	knuckles_vs_rouge_aftermath                            = 24,
	sonic_and_dr_eggman_face_off                           = 25,
	sonic_saves_himself                                    = 26,
	sonic_and_shadows_final_battle                         = 27,
	hero_story_ending                                      = 28,
	// hero - unlisted
	in_a_mountainous_region                                = 50,
	day_x_hero                                             = 51,
	mountainous_region_mine                                = 52,
	outside_the_space_colony_ark                           = 53,
	inside_the_space_colony_ark_hero                       = 54,
	// dark
	dark_story_intro                                       = 100,
	dr_eggman_awakens_shadow                               = 101,
	shadow_instructs_dr_eggman                             = 102,
	rouge_meets_knuckles                                   = 103,
	dr_eggman_hears_of_shadows_break_in                    = 105,
	shadows_pathos                                         = 106,
	shadow_meets_sonic                                     = 107,
	rouge_follows_dr_eggman                                = 109,
	gathering_of_the_dark                                  = 111,
	arrive_on_prison_island                                = 112,
	dr_eggmans_plan_is_complicated_by_tails_and_amy        = 113,
	shadows_conscience_begins_to_surface                   = 116,
	shadow_vs_sonic_aftermath                              = 118,
	shadows_past_life_with_maria                           = 119,
	dr_eggman_reworks_his_plan                             = 120,
	shadow_spots_the_heroes_approaching_the_pyramid_base   = 122,
	dr_eggman_fails_to_ambush_sonic_inside_the_base        = 123,
	rouge_learns_the_truth_about_project_shadow            = 124,
	rouge_vs_knuckles_aftermath                            = 126,
	dr_eggmans_final_plan_to_crush_the_heroes              = 127,
	dr_eggman_sets_a_diabolical_trap_for_sonic             = 128,
	mystery_of_shadow_the_hedgehog                         = 129,
	shadow_and_sonics_final_battle                         = 130,
	dark_story_ending                                      = 131,
	// dark - unlisted
	desert_area                                            = 150,
	in_the_pyramid                                         = 151,
	inside_the_space_colony_ark_dark                       = 152,
	day_x_dark                                             = 153,
	near_the_capital_city                                  = 154,
	// last
	last_story_intro                                       = 200,
	the_ark_falls                                          = 201,
	geralds_diary_and_descent_into_madness                 = 203,
	shadow_and_amy                                         = 204,
	geralds_loss_and_despair                               = 205,
	knuckles_stops_the_chaos_emeralds                      = 206,
	sonic_and_shadow_transform                             = 207,
	shadow_saves_the_world                                 = 208,
	last_story_ending_and_credits                          = 210,
	epilogue                                               = 211,
	// intros
	sa2_intro_dreamcast                                    = 350,
	japanese_sa2b_intro                                    = 360,
	english_sa2b_intro                                     = 361,
	// SA2: The Trial only - video
	sonic_adventure_2_trailer                              = 400,
	// videos
	sa2_intro                                              = 401,
	prison_island_explodes                                 = 409,
	dr_eggmans_threat_to_earth                             = 411,
	sonic_and_friends_go_to_space_hero                     = 420,
	// perhaps is part of the hero_story_ending? it does not load ingame.
	the_eclipse_cannon_malfunctions                        = 428,
	// videos, continued
	dark_story_trailer                                     = 429,
	last_story_trailer                                     = 430,
	sonic_and_friends_go_to_space_dark                     = 524,
	hero_story_trailer                                     = 532,
	geralds_revenge                                        = 602,
	// perhaps is part of the shadow_saves_the_world? it does not load ingame.
	the_ark_is_neutralized                                 = 609
};

/// similar to event enum, but for gameplay events...
/// these have awful names, because I can not name things myself.
enum class gameplay_event {
	f_6t_big_foot     = 1,
	sonic_vs_shadow   = 7,
	green_forest      = 8,
	pumpkin_hill      = 10,
	unused            = 12,
	aquatic_mine      = 13,
	king_boom_boo     = 18,
	knuckles_vs_rouge = 23,
	sand_ocean        = 104,
	egg_quarters      = 108,
	lost_colony       = 110,
	security_hall     = 114,
	r_1a_flying_dog   = 115,
	shadow_vs_sonic   = 117,
	sky_rail          = 121,
	rouge_vs_knuckles = 125
};

static auto& current_event = ref<event>(0x1A28AF4);
// alternatively 0x1945718 seems to be the same.
// the only condition I know of for whether event is a gameplay event is:
//   MainCharObj1[0]->Action == Actions::Action_CutsceneAnimation
// and it might not be true for all gameplay events.
static auto& current_gameplay_event = ref<gameplay_event>(0x1732AC4);

std::optional<std::string> event_name(event event);
std::optional<std::string> gameplay_event_name(gameplay_event gameplay_event);

std::optional<std::string> event_asset_name(event event);

/// events with a single line normally only last a few seconds.
/// these also do not make good large image assets.
bool event_should_be_skipped(event event);
