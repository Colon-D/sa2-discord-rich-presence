#include "sa2_discord_rich_presence/character.h"
#include "sa2_discord_rich_presence/player.h"
#include <iostream>

Characters super_character(const Characters character) {
	switch (character) {
	case Characters_Sonic:
		return Characters::Characters_SuperSonic;
	case Characters_Shadow:
		return Characters::Characters_SuperShadow;
	default:
		std::cerr << "sa2-discord-rich-presence:\n";
		std::cerr << "\tsuper_character:\n";
		std::cerr << "\t\tError: Character " << +character
			<< " does not have an super character.\n";
		return character;
	}
}

Characters alternative_character(const Characters character) {
	switch (character) {
	case Characters_Sonic:
		return Characters::Characters_Amy;
	case Characters_Shadow:
		return Characters::Characters_MetalSonic;
	case Characters_Knuckles:
		return Characters::Characters_Tikal;
	case Characters_Rouge:
		return Characters::Characters_Chaos;
	case Characters_MechTails:
		return Characters::Characters_ChaoWalker;
	case Characters_MechEggman:
		return Characters::Characters_DarkChaoWalker;
	default:
		std::cerr << "sa2-discord-rich-presence:\n";
		std::cerr << "\talternative_character:\n";
		std::cerr << "\t\tError: Character " << +character
			<< " does not have an alternative character.\n";
		return character;
	}
}

Characters current_character(std::size_t player) {
	player = current_player(player);
	// final hazard does not use the CurrentCharacter memory locations,
	// it seems that Super Sonic and Super Shadow are hardcoded
	// (or in a different memory location)
	if (CurrentLevel == LevelIDs::LevelIDs_FinalHazard) {
		if (player == 0) {
			return Characters::Characters_SuperSonic;
		}
		return Characters::Characters_SuperShadow;
	}
	Characters character{};
	// if controlling character 0, get character 0, else get character 1
	if (player == 0) {
		character = static_cast<Characters>(CurrentCharacter);
	}
	else {
		character = static_cast<Characters>(CurrentCharacter2P);
	}
	// if not in a kart race and character is into alternative rock,
	// get the alternative character
	if (
		CurrentLevel != LevelIDs::LevelIDs_KartRace
		&& CurrentLevel != LevelIDs::LevelIDs_Route101280
		&& AltCharacter[player] != 0
	) {
		character = alternative_character(character);
	}
	// if the character has... super sonic upgrade? get the super character
	if (
		MainCharObj2[player] != nullptr
		&& (
			MainCharObj2[player]->Upgrades & Upgrades::Upgrades_SuperSonic
		) != 0
	) {
		character = super_character(character);
	}
	return character;
}

std::string character_name(const Characters character) {
	// named after the multiplayer menu if possible (not capitalized)), ie:
	// - Dr. Eggman has their Dr. title,
	// - Mech's are not stated for Tails and Dr. Eggman (unless mechless),
	// - Chaos Zero is named Chaos Zero and not Chaos nor Chaos 0
	switch (character) {
	case Characters::Characters_Sonic:
		return "Sonic";
	case Characters::Characters_Tails:
		return "Tails (Mechless)";
	case Characters::Characters_MechTails:
		return "Tails";
	case Characters::Characters_Knuckles:
		return "Knuckles";
	case Characters::Characters_Shadow:
		return "Shadow";
	case Characters::Characters_Rouge:
		return "Rouge";
	case Characters::Characters_Eggman:
		return "Dr. Eggman (Mechless)";
	case Characters::Characters_MechEggman:
		return "Dr. Eggman";
	case Characters::Characters_Amy:
		return "Amy";
	case Characters::Characters_MetalSonic:
		return "Metal Sonic";
	case Characters::Characters_ChaoWalker:
		return "Chao Walker";
	case Characters::Characters_DarkChaoWalker:
		if (
			const auto mod = mods.find("Dreamcast Characters");
			mod != mods.end()
		) {
			if (
				mod->second->getString("Characters", "DarkChaoWalker") != "Dark Chao Walker"
			) {
				return "Big the Cat";
			}
		}
		return "Dark Chao Walker";
	case Characters::Characters_Tikal:
		return "Tikal";
	case Characters::Characters_Chaos:
		return "Chaos Zero";
	case Characters::Characters_SuperSonic:
		return "Super Sonic";
	case Characters::Characters_SuperShadow:
		return "Super Shadow";
	case Characters::Characters_B:
		return "🅱️";
	default:
		return "Unknown";
	}
}

enum character_class character_class(const Characters character) {
	switch (character) {
	case Characters::Characters_Sonic:
	case Characters::Characters_Shadow:
	case Characters::Characters_Amy:
	case Characters::Characters_MetalSonic:
	case Characters::Characters_SuperSonic:
	case Characters::Characters_SuperShadow:
		return character_class::action;
	case Characters::Characters_Knuckles:
	case Characters::Characters_Rouge:
	case Characters::Characters_Tikal:
	case Characters::Characters_Chaos:
		return character_class::treasure_hunting;
	case Characters::Characters_MechTails:
	case Characters::Characters_MechEggman:
	case Characters::Characters_ChaoWalker:
	case Characters::Characters_DarkChaoWalker:
		return character_class::shooting;
	default:
		return character_class::other;
	}
}

std::string character_class_battle_name(
	const enum character_class character_class
) {
	switch (character_class) {
	case character_class::action:
		return "Action Race Battle";
	case character_class::shooting:
		return "Shooting Battle";
	case character_class::treasure_hunting:
		return "Treasure Hunt Race";
	default:
		return "Unknown";
	}
}

Characters opposite_polarity(const Characters character) {
	switch (character) {
	case Characters::Characters_Sonic:
		return Characters::Characters_Shadow;
	case Characters::Characters_Shadow:
		return Characters::Characters_Sonic;
	case Characters::Characters_Tails:
		return Characters::Characters_Eggman;
	case Characters::Characters_Eggman:
		return Characters::Characters_Tails;
	case Characters::Characters_Knuckles:
		return Characters::Characters_Rouge;
	case Characters::Characters_Rouge:
		return Characters::Characters_Knuckles;
	case Characters::Characters_MechTails:
		return Characters::Characters_MechEggman;
	case Characters::Characters_MechEggman:
		return Characters::Characters_MechTails;
	case Characters::Characters_Amy:
		return Characters::Characters_MetalSonic;
	case Characters::Characters_SuperSonic:
		return Characters::Characters_SuperShadow;
	case Characters::Characters_SuperShadow:
		return Characters::Characters_SuperSonic;
	case Characters::Characters_MetalSonic:
		return Characters::Characters_Amy;
	case Characters::Characters_ChaoWalker:
		return Characters::Characters_DarkChaoWalker;
	case Characters::Characters_DarkChaoWalker:
		return Characters::Characters_ChaoWalker;
	case Characters::Characters_Tikal:
		return Characters::Characters_Chaos;
	case Characters::Characters_Chaos:
		return Characters::Characters_Tikal;
	default:
		std::cerr << "sa2-discord-rich-presence:\n";
		std::cerr << "\topposite_polarity:\n";
		std::cerr << "\t\tError: Character " << +character
			<< " has no opposite polarity.\n";
		return character;
	}
}
