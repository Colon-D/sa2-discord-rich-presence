#include "sa2_discord_rich_presence/events.h"
#include <unordered_map>

std::unordered_map<event, std::string> event_names {
	{ event::hero_story_intro,                                       "Hero Story intro"                                      },
	{ event::sonic_meets_shadow,                                     "Sonic meets Shadow"                                    },
	{ event::knuckles_meets_rouge,                                   "Knuckles meets Rouge"                                  },
	{ event::tails_flies_to_prison_island,                           "Tails flies to Prison Island"                          },
	{ event::tails_vs_dr_eggman_aftermath,                           "Tails vs. Dr. Eggman Aftermath"                        },
	{ event::sonic_escapes_from_his_cell,                            "Sonic escapes from his cell"                           },
	{ event::sonic_and_friends_witness_the_arks_power,               "Sonic and friends witness the ARK's power"             },
	{ event::wheres_dr_eggman,                                       "Where's Dr. Eggman?"                                   },
	{ event::sonic_and_tails_intercept_dr_eggmans_video,             "Sonic and Tails intercept Dr. Eggman's video"          },
	{ event::locate_dr_eggmans_pyramid_base,                         "Locate Dr. Eggman's pyramid base"                      },
	{ event::knuckles_begins_looking_for_the_gate_keys,              "Knuckles begins looking for the gate keys"             },
	{ event::dr_eggman_ambushes_sonic_inside_the_base,               "Dr. Eggman Ambushes Sonic inside the base"             },
	{ event::tails_explains_his_plans_to_destroy_the_eclipse_cannon, "Tails explains his plan to destroy the Eclipse Cannon" },
	{ event::sonic_receives_a_call_for_ransom_from_dr_eggman,        "Sonic receives a call for ransom from Dr. Eggman"      },
	{ event::knuckles_vs_rouge_aftermath,                            "Knuckles vs. Rouge aftermath"                          },
	{ event::sonic_and_dr_eggman_face_off,                           "Sonic and Dr. Eggman face off"                         },
	{ event::sonic_saves_himself,                                    "Sonic saves himself"                                   },
	{ event::sonic_and_shadows_final_battle,                         "Sonic and Shadow's final battle"                       },
	{ event::hero_story_ending,                                      "Hero Story ending"                                     },
	{ event::dark_story_intro,                                       "Dark Story intro"                                      },
	{ event::dr_eggman_awakens_shadow,                               "Dr. Eggman awakens Shadow"                             },
	{ event::shadow_instructs_dr_eggman,                             "Shadow instructs Dr. Eggman"                           },
	{ event::rouge_meets_knuckles,                                   "Rouge meets Knuckles"                                  },
	{ event::dr_eggman_hears_of_shadows_break_in,                    "Dr. Eggman hears of Shadow's break-in"                 },
	{ event::shadows_pathos,                                         "Shadow's pathos"                                       },
	{ event::shadow_meets_sonic,                                     "Shadow meets Sonic"                                    },
	{ event::rouge_follows_dr_eggman,                                "Rouge follows Dr. Eggman"                              },
	{ event::gathering_of_the_dark,                                  "Gathering of the Dark"                                 },
	{ event::arrive_on_prison_island,                                "Arrive on Prison Island"                               },
	{ event::dr_eggmans_plan_is_complicated_by_tails_and_amy,        "Dr. Eggman's plan is complicated by Tails and Amy"     },
	{ event::shadows_conscience_begins_to_surface,                   "Shadow's conscience begins to surface"                 },
	{ event::shadow_vs_sonic_aftermath,                              "Shadow vs. Sonic aftermath"                            },
	{ event::shadows_past_life_with_maria,                           "Shadow's past life with Maria"                         },
	{ event::dr_eggman_reworks_his_plan,                             "Dr. Eggman reworks his plan"                           },
	{ event::shadow_spots_the_heroes_approaching_the_pyramid_base,   "Shadow spots the Heroes approaching the pyramid base"  },
	{ event::dr_eggman_fails_to_ambush_sonic_inside_the_base,        "Dr. Eggman fails to ambush Sonic inside the base"      },
	{ event::rouge_learns_the_truth_about_project_shadow,            "Rouge learns the truth about Project Shadow"           },
	{ event::rouge_vs_knuckles_aftermath,                            "Rouge vs. Knuckles aftermath"                          },
	{ event::dr_eggmans_final_plan_to_crush_the_heroes,              "Dr. Eggman's final plan to crush the Heroes"           },
	{ event::dr_eggman_sets_a_diabolical_trap_for_sonic,             "Dr. Eggman sets a diabolical trap for Sonic"           },
	{ event::mystery_of_shadow_the_hedgehog,                         "Mystery of Shadow the Hedgehog"                        },
	{ event::shadow_and_sonics_final_battle,                         "Shadow and Sonic's final battle"                       },
	{ event::dark_story_ending,                                      "Dark Story ending"                                     },
	{ event::last_story_intro,                                       "Last Story intro"                                      },
	{ event::the_ark_falls,                                          "The ARK falls"                                         },
	{ event::geralds_diary_and_descent_into_madness,                 "Gerald's diary and descent into madness"               },
	{ event::shadow_and_amy,                                         "Shadow and Amy"                                        },
	{ event::geralds_loss_and_despair,                               "Gerald's loss and despair"                             },
	{ event::knuckles_stops_the_chaos_emeralds,                      "Knuckles stops the Chaos Emeralds"                     },
	{ event::sonic_and_shadow_transform,                             "Sonic and Shadow transform"                            },
	{ event::shadow_saves_the_world,                                 "Shadow saves the world"                                },
	{ event::last_story_ending_and_credits,                          "Last Story ending/credits"                             },
	{ event::epilogue,                                               "Epilogue"                                              },
	{ event::sa2_intro_dreamcast,                                    "Sonic Adventure 2 intro"                               },
	{ event::japanese_sa2b_intro,                                    "Sonic Adventure 2: Battle intro"                       },
	{ event::english_sa2b_intro,                                     "Sonic Adventure 2: Battle intro"                       },
	{ event::sonic_adventure_2_trailer,                              "Sonic Adventure 2 trailer"                             },
	{ event::sa2_intro,                                              "Sonic Adventure 2 intro"                               },
	{ event::prison_island_explodes,                                 "Prison Island explodes"                                },
	{ event::dr_eggmans_threat_to_earth,                             "Dr. Eggman's threat to earth"                          },
	{ event::sonic_and_friends_go_to_space_hero,                     "Sonic and friends go to space (hero)"                  },
	{ event::the_eclipse_cannon_malfunctions,                        "The Eclipse Cannon malfunctions"                       },
	{ event::dark_story_trailer,                                     "Dark Story trailer"                                    },
	{ event::last_story_trailer,                                     "Last Story trailer"                                    },
	{ event::sonic_and_friends_go_to_space_dark,                     "Sonic and friends go to space (dark)"                  },
	{ event::hero_story_trailer,                                     "Hero Story trailer"                                    },
	{ event::geralds_revenge,                                        "Gerald's revenge"                                      },
	{ event::the_ark_is_neutralized,                                 "The ARK is neutralized"                                },
	// events I do not give the pleasure of rpc to
	{ event::in_a_mountainous_region,          "In a mountainous region"            },
	{ event::day_x_hero,                       "Day X (hero)"                       },
	{ event::mountainous_region_mine,          "Mountainous region: Mine"           },
	{ event::outside_the_space_colony_ark,     "Outside the Space Colony ARK"       },
	{ event::inside_the_space_colony_ark_hero, "Inside the Space Colony ARK (hero)" },
	{ event::desert_area,                      "Desert area"                        },
	{ event::in_the_pyramid,                   "In the pyramid"                     },
	{ event::inside_the_space_colony_ark_dark, "Inside the Space Colony ARK (dark)" },
	{ event::day_x_dark,                       "Day X (dark)"                       },
	{ event::near_the_capital_city,            "Near the capital city"              }
};

std::optional<std::string> event_name(const event event) {
	if (
		const auto event_name = event_names.find(event);
		event_name != event_names.end()
	) {
		return event_name->second;
	}
	return {};
}

std::optional<std::string> gameplay_event_name(
	const gameplay_event gameplay_event
) {
	switch (gameplay_event) {
	case gameplay_event::f_6t_big_foot:
		return "F-6t Big Foot";
	case gameplay_event::sonic_vs_shadow:
		return "Sonic vs. Shadow";
	case gameplay_event::green_forest:
		return "Green Forest";
	case gameplay_event::pumpkin_hill:
		return "Pumpkin Hill";
	case gameplay_event::unused:
		return "Unused";
	case gameplay_event::aquatic_mine:
		return "Aquatic Mine";
	case gameplay_event::king_boom_boo:
		return "King Boom Boo";
	case gameplay_event::knuckles_vs_rouge:
		return "Knuckles vs. Rouge";
	case gameplay_event::sand_ocean:
		return "Sand Ocean";
	case gameplay_event::egg_quarters:
		return "Egg Quarters";
	case gameplay_event::lost_colony:
		return "Lost Colony";
	case gameplay_event::security_hall:
		return "Security Hall";
	case gameplay_event::r_1a_flying_dog:
		return "R-1/A Flying Dog";
	case gameplay_event::shadow_vs_sonic:
		return "Shadow vs. Sonic";
	case gameplay_event::sky_rail:
		return "Sky Rail";
	case gameplay_event::rouge_vs_knuckles:
		return "Rouge vs. Knuckles";
	}

	// if unknown, and in multiplayer, it is probably the multiplayer intro
	if (TwoPlayerMode != 0) {
		return "2P intro";
	}

	// else, idk what you have come across
	return {};
}

std::optional<std::string> event_asset_name(event event) {
	// check event is known
	if (!event_names.contains(event)) {
		return {};
	}
	// check event should not be skipped
	if (event_should_be_skipped(event)) {
		return {};
	}
	switch (event) {
		// replace events without assets with a similar asset
		case event::rouge_vs_knuckles_aftermath:
			event = event::knuckles_vs_rouge_aftermath;
			break;
  		case event::shadow_and_sonics_final_battle:
			event = event::sonic_and_shadows_final_battle;
			break;
  		case event::english_sa2b_intro:
			event = event::japanese_sa2b_intro;
			break;
  		case event::sa2_intro:
			event = event::sa2_intro_dreamcast;
			break;
  		case event::the_eclipse_cannon_malfunctions:
			event = event::hero_story_ending;
			break;
  		case event::the_ark_is_neutralized:
			event = event::shadow_saves_the_world;
			break;
		default:
			break;
	}
	// return the asset name
	return "event_" + std::to_string(static_cast<int>(event));
}

bool event_should_be_skipped(const event event) {
	// how does it feel, dumb stinky event? to be skipped?
	// even event::sonic_adventure_2_trailer has an asset, and it can't even be
	// played! Well, at least it lasts more than a second.

	switch (event) {
		case event::in_a_mountainous_region:
		case event::day_x_hero:
		case event::mountainous_region_mine:
		case event::outside_the_space_colony_ark:
		case event::inside_the_space_colony_ark_hero:
		case event::desert_area:
		case event::in_the_pyramid:
		case event::inside_the_space_colony_ark_dark:
		case event::day_x_dark:
		case event::near_the_capital_city:
			return true;
		default:
			return false;
	}
}
