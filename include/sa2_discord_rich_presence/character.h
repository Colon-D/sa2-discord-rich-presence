#pragma once
#include "sa2_discord_rich_presence/modding.h"
#include <string>

Characters super_character(Characters character);

Characters alternative_character(Characters character);

/// returns current character from player index,
/// ironically CurrentCharacter does not return the current character :)
Characters current_character(std::size_t player = 0);

std::string character_name(Characters character);

/// character classes: action, shooting, treasure hunting or other.
/// Super Sonic and Super Shadow are considered action as they can be
/// transformed into during an action race with Sora's mod.
/// I have no clue what Mechless Tails and Mechless Eggman are...
enum class character_class {
	action, // sonic, shadow, amy, metal sonic, super sonic and super shadow
	shooting, // tails, eggman, chao walker and dark chao walker
	treasure_hunting, // knuckles, rouge, tikal and chaos
	other // mechless tails, mechless eggman and whoever the hell B is
};

character_class character_class(Characters character);

std::string character_class_battle_name(enum character_class character_class);

Characters opposite_polarity(Characters character);
