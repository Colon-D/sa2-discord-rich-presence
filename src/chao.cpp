#include "sa2_discord_rich_presence/chao.h"
#include "sa2_discord_rich_presence/ini_settings.h"
#include "sa2_discord_rich_presence/modding.h"
#include <array>
#include <cassert>

std::string chao_race_course_name(
	const std::uint8_t chao_race_course,
	const std::uint8_t chao_race_level,
	const bool         newer_challenge_race_mod
) {
	std::string course_name{ "Unknown" };
	switch (chao_race_course) {
	// beginner
	case 0:
		course_name = "Crab Pool";
		break;
	case 1:
		course_name = "Stump Valley";
		break;
	case 2:
		course_name = "Mushroom Forest";
		break;
	case 3:
		course_name = "Block Canyon";
		break;
	// jewel
	case 4:
		course_name = "Aquamarine";
		break;
	case 5:
		course_name = "Topaz";
		break;
	case 6:
		course_name = "Peridot";
		break;
	case 7:
		course_name = "Garnet";
		break;
	case 8:
		course_name = "Onyx";
		break;
	case 9:
		course_name = "Diamond";
		break;
	// challenge
	case 10:
		if (newer_challenge_race_mod) {
			switch (chao_race_level) {
			case 0:
				course_name = "Rematch! The jewel Chao and the moon Chao!";
				break;
			case 1:
				course_name = "Catch Me!";
				break;
			case 2:
				course_name = "Me First!";
				break;
			case 3:
				course_name = "Smash B fast and Boost!";
				break;
			case 4:
				course_name = "Oh No! Attack of Unfair Chao!";
				break;
			case 5:
				course_name = "Cold Water!";
				break;
			case 6:
				course_name = "It's too Hot! Need Stamina";
				break;
			case 7:
				course_name = "Look.. That's your Chao..";
				break;
			case 8:
				course_name = "Be Strong! Chaos group.";
				break;
			case 9:
				course_name = "Race of S Ranks!";
				break;
			case 10:
				course_name = "Remember us? Last Chance";
				break;
			case 11:
				course_name = "This is the Ultimate Rematch!";
				break;
			}
		}
		else {
			switch (chao_race_level) {
			case 0:
				course_name = "Gold and Silver Rivals";
				break;
			case 1:
				course_name = "He Returns";
				break;
			case 2:
				course_name = "I'm Trying!";
				break;
			case 3:
				course_name = "Small Animal Challenge";
				break;
			case 4:
				course_name = "Cockroach Chao Group";
				break;
			case 5:
				course_name = "Oh, My Egg!";
				break;
			case 6:
				course_name = "Skeleton Group";
				break;
			case 7:
				course_name = "Pumpkin Group";
				break;
			case 8:
				course_name = "Ghost Group";
				break;
			case 9:
				course_name = "He Strikes Back";
				break;
			case 10:
				course_name = "Chao Ranger";
				break;
			case 11:
				course_name = "Ultimate Rival";
				break;
			}
		}
		break;
	// hero
	case 11:
		switch (chao_race_level) {
		case 0:
			course_name = "Baby Devil";
			break;
		case 1:
			course_name = "Child Devil";
			break;
		case 2:
			course_name = "Death Troops";
			break;
		case 3:
			course_name = "Devil vs Angel";
			break;
		}
	// dark
	case 12:
		switch (chao_race_level) {
		case 0:
			course_name = "Baby Angel";
			break;
		case 1:
			course_name = "Angels";
			break;
		case 2:
			course_name = "Flying Angels";
			break;
		case 3:
			course_name = "Angel vs Devil";
			break;
		}
	}

	// if in a single-player race, append chao race level
	if (player_chao_in_chao_race() == 1) {
		// if beginner, there are 3 levels
		if (chao_race_course < 4) {
			course_name += " - " + std::to_string(chao_race_level + 1) + "/3";
		}
		// if jewel, there are 5 levels
		else if (chao_race_course < 10) {
			course_name += " - " + std::to_string(chao_race_level + 1) + "/5";
		}
		// else, level is used to further specify which challenge/hero/dark
		// course should be used
	}
	return course_name;
}

std::string chao_karate_level_name(
	const std::uint8_t  chao_karate_level,
	const bool          chao_karate_busters_tournament_mod,
	const std::optional<bool> chao_karate_busters_tournament_extra_mode,
	const std::optional<bool> chao_karate_busters_tournament_encore_mode
) {
	std::string level_name{ "Unknown" };
	if (chao_karate_busters_tournament_mod) {
		// if chao_karate_busters_tournament_extra_mode is set and equal to true
		if (chao_karate_busters_tournament_extra_mode.value_or(false)) {
			switch (chao_karate_level) {
			case 0:
				level_name = "Challenge 1";
				break;
			case 1:
				level_name = "Challenge 2";
				break;
			case 2:
				level_name = "All-Star";
				break;
			case 3:
				level_name = "Finale";
				break;
			}
		}
		else {
			switch (chao_karate_level) {
			case 0:
				level_name = "Rank 1";
				break;
			case 1:
				level_name = "Rank 2";
				break;
			case 2:
				level_name = "Rank 3";
				break;
			case 3:
				level_name = "Rank 4";
				break;
			}
		}
		if (chao_karate_busters_tournament_encore_mode.value_or(false)) {
			level_name += " - Encore";
		}
	}
	else {
		switch (chao_karate_level) {
		case 0:
			level_name = "Beginner";
			break;
		case 1:
			level_name = "Standard";
			break;
		case 2:
			level_name = "Expert";
			break;
		case 3:
			level_name = "Super";
			break;
		}
	}
	return level_name;
}

std::unordered_map<chao_area, name_and_image_asset_boolean> chao_area_names{
	{ chao_area::chao_lobby,             { "Chao Lobby"            , true } },
	{ chao_area::chao_garden,            { "Chao Garden"           , true } },
	{ chao_area::hero_garden,            { "Hero Garden"           , true } },
	{ chao_area::dark_garden,            { "Dark Garden"           , true } },
	{ chao_area::chao_race_entrance,     { "Chao Race Entrance"    , true } },
	{ chao_area::chao_kindergarten,      { "Chao Kindergarten"     , true } },
	{ chao_area::chao_stadium,           { "Chao Stadium"          , true } },
	{ chao_area::chao_karate,            { "Chao Karate"           , true } },
	{ chao_area::chao_departure_machine, { "Chao Departure machine", true } },
	{ chao_area::chao_race,              { "Chao Race"             , true } },
	{ chao_area::chao_karate,            { "Chao Karate"           , true } }
};

std::string chao_area_name(
	const chao_area                   chao_area,
	const std::optional<std::uint8_t> chao_race_course,
	const std::optional<std::uint8_t> chao_race_level
) {
	return chao_area_name_and_image_asset_boolean(
		chao_area, chao_race_course, chao_race_level
	).name;
}

name_and_image_asset_boolean chao_area_name_and_image_asset_boolean(
	chao_area                         chao_area,
	const std::optional<std::uint8_t> chao_race_course,
	const std::optional<std::uint8_t> chao_race_level
) {
	switch (chao_area) {
	case chao_area::chao_lobby_alternative:
		chao_area = chao_area::chao_lobby;
		break;
	case chao_area::chao_race_entrance_2p:
		chao_area = chao_area::chao_race_entrance;
		break;
	case chao_area::chao_karate_2p:
		chao_area = chao_area::chao_karate;
		break;
	default:
		break;
	}

	if (
		const auto it = chao_area_names.find(chao_area);
		it != chao_area_names.end()
	) {
		return it->second;
	}

	// else, loading for the first time or in an unknown area
	return { "Unknown", true };
}

void set_chao_area_name(
	const chao_area    chao_area,
	const std::string& name,
	const bool         has_image_asset
) {
	const auto chao_area_name = chao_area_names.find(chao_area);
	assert(chao_area_name != chao_area_names.end());
	chao_area_name->second = { name, has_image_asset };
}

std::string current_chao_area_name() {
	return chao_area_name(
		current_chao_area,
		current_chao_race_course,
		current_chao_race_level
	);
}

const char* chao_name_decoding_not_allowed_exception::what() const noexcept {
	return "chao name decoding is not allowed whilst "
		"allow_decoding_of_chao_names is false";
};

std::string decode_chao_char(
	const char encoded_chao_char, const bool cpu_name
) {
	if (!cpu_name && !ini::chao_names) {
		throw chao_name_decoding_not_allowed_exception{};
	}
	// can't use one big string as the [] operator will be bytes and not utf-8
	// characters. First character, '\0' can not use the c string constructor
	// for std::string_view, as the string instantly be terminated and thus
	// empty. might have some mistakes as I manually typed this using Chao 
	// Island's Chao Name Encoding guide.
	// If Chao World Extended is detected, '…' needs to be replaced with a ♥
	constexpr std::array<std::string_view, 256> decode_map{
		std::string_view{ "\0", 1 },  "!",  "\"", "#",  "$",  "%",  "&",  "'",
		"(",  ")",  "*",  "+",  ",",  "-",  ".",  "/",  "0",  "1",  "2",  "3",
		"4",  "5",  "6",  "7",  "8",  "9",  ":",  ";",  "<",  "=",  ">",  "?",
		"@",  "A",  "B",  "C",  "D",  "E",  "F",  "G",  "H",  "I",  "J",  "K",
		"L",  "M",  "N",  "O",  "P",  "Q",  "R",  "S",  "T",  "U",  "V",  "W",
		"X",  "Y",  "Z",  "[",  "¥",  "]",  "^",  "_",  "'",  "a",  "b",  "c",
		"d",  "e",  "f",  "g",  "h",  "i",  "j",  "k",  "l",  "m",  "n",  "o",
		"p",  "q",  "r",  "s",  "t",  "u",  "v",  "w",  "x",  "y",  "z",  "{",
		"|",  "}",  "~",  " ",  "À",  "Á",  "Â",  "Ã",  "Ä",  "Å",  "Æ",  "Ç",
		"È",  "É",  "Ê",  "Ë",  "Ì",  "Í",  "Î",  "Ï",  "Ð",  "Ñ",  "Ò",  "Ó",
		"Ô",  "Õ",  "Ö",  "¿",  "Ø",  "Ù",  "Ú",  "Û",  "Ü",  "Ý",  "Þ",  "ß",
		"à",  "á",  "â",  "ã",  "ä",  "å",  "æ",  "ç",  "è",  "é",  "ê",  "ë",
		"ì",  "í",  "î",  "ï",  "ð",  "ñ",  "ò",  "ó",  "ô",  "õ",  "ö",  "¡",
		"ø",  "ù",  "ú",  "û",  "ü",  "ý",  "þ",  "ÿ",  "ァ", "ア", "ィ", "イ",
		"ゥ", "ウ", "ェ", "エ", "ォ", "オ", "カ", "ガ", "キ", "ギ", "ク", "グ",
		"ケ", "ゲ", "コ", "ゴ", "サ", "ザ", "シ", "ジ", "ス", "ズ", "セ", "ゼ",
		"ソ", "ゾ", "タ", "ダ", "チ", "ヂ", "ッ", "ツ", "ヅ", "テ", "デ", "ト",
		"ド", "ナ", "ニ", "ヌ", "ネ", "ノ", "ハ", "バ", "パ", "ヒ", "ビ", "ピ",
		"フ", "ブ", "プ", "ヘ", "ベ", "ペ", "ホ", "ボ", "ポ", "マ", "ミ", "ム",
		"メ", "モ", "ャ", "ヤ", "ュ", "ユ", "ョ", "ヨ", "ラ", "リ", "ル", "レ",
		"ロ", "ヮ", "ワ", "ﾞ",  "ﾟ",  "ヲ", "ン", "。", "、", "〒", "・", "★",
		"♀",  "♂",  "♪",  "…",  "「", "」", "ヴ", " "
	};
	const auto encoded_chao_character_u8 =
		static_cast<std::uint8_t>(encoded_chao_char);
	std::string decoded_chao_character{
		decode_map[static_cast<std::size_t>(encoded_chao_character_u8)]
	};
	if (
		mods.contains("Chao World Extended")
		&& decoded_chao_character == "…"
	) {
		decoded_chao_character = "♥";
	}
	return decoded_chao_character;
}

std::string decode_chao_name(
	const char* const encoded_chao_name,
	const std::size_t maximum_length,
	const bool        cpu_name
) {
	std::string decoded_chao_name{};
	// go through each encoded chao character, decode it, and append it to the
	// decoded chao name
	for (
		std::size_t char_index{ 0 };
		char_index < maximum_length;
		++char_index
	) {
		// get character to decode
		const auto encoded_chao_char = encoded_chao_name[char_index];
		// if a null character has been reached, stop decoding name
		if (encoded_chao_char == '\0') {
			break;
		}
		// decode character and append to decoded chao name
		decoded_chao_name +=
			decode_chao_char(encoded_chao_name[char_index], cpu_name);
	}
	return decoded_chao_name;
}

std::string decode_chao_name(
	const ChaoDataBase& chao_data,
	bool                cpu_name
) {
	if (
		mods.contains("Chao World Extended")
	) {
		constexpr std::size_t cwe_name_offset{ 0x624 };
		return decode_chao_name(
			reinterpret_cast<const char*>(&chao_data)
				+ cwe_name_offset,
			12,
			cpu_name
		);
	}
	return decode_chao_name(chao_data.Name, 7, cpu_name);
}

std::size_t player_chao_in_chao_race() {
	// if we have cwe
	// and are replacing beginner and jewel races with 8p races
	// and are in a beginner or jewel race
	// then we have 8 player chao in the race
	const auto cwe_it = mods.find("Chao World Extended");
	const bool cwe = cwe_it != mods.end();
	if (
		cwe
		&& cwe_it->second->getBool(
			"Race", "RaceJewelandBeginnerRacebecome8PPartyRace"
		)
		&& current_chao_race_course < 10
	) {
		return 8;
	}
	// otherwise, if the last chao area was the 2p chao race entrance
	// then we have 2 player chao in the race
	if (
		static_cast<chao_area>(LastChaoArea)
		== chao_area::chao_race_entrance_2p
	) {
		return 2;
	}
	// finally, we have 1 player chao in the race
	return 1;
}

chao_karate_chao_data2* chao_karate::chao_karate_chao_data2(
	const std::size_t chao_index
) {
	return static_cast<::chao_karate_chao_data2*>(
		chao_karate_chao_object[chao_index]->Data2.Undefined
	);
}

bool in_chao_karate_match() {
	return chao_karate != nullptr
		&& chao_karate->chao_karate_chao_object[0] != nullptr;
}

void update_chao_race_rpc(discord::rich_presence& rpc) {
	// if in hero or dark race, set large_image_key to hero_race or dark_race
	if (current_chao_race_course == 11) {
		rpc.large_image_key = "hero_race";
	}
	else if (current_chao_race_course == 12) {
		rpc.large_image_key = "dark_race";
	}
	// append race course name to large image text
	rpc.large_image_text +=
		" (" +
		chao_race_course_name(
			current_chao_race_course,
			current_chao_race_level,
			mods.contains("Newer Challenge Race")
		)
		+ ')';
	// set small_image_key to chao
	rpc.small_image_key = "chao_race_icon";
	// set small_image_text to chao names and places
	const auto player_chao_count = player_chao_in_chao_race();
	if (ini::chao_names) {
		rpc.small_image_text = "";

		const auto* const chao_data_array = &ChaoDataArray;
		// go through each chao
		for (
			std::size_t chao_index{ 0 };
			chao_index < player_chao_count;
			++chao_index
		) {
			if (const auto* const chao = chao_data_array[chao_index * 0x12]) {
				// get the chao name and decode it
				const auto name = decode_chao_name(chao->data);

				// append it to rpc
				rpc.small_image_text += '`' + name + '`';

				// add seperator
				if (chao_index < player_chao_count - 1) {
					rpc.small_image_text += ", ";
				}
			}
		}
	}
	else {
		if (player_chao_count == 1) {
			rpc.small_image_text = "Racing Chao";
		}
		else {
			rpc.small_image_text =
				"Racing Chao (" + std::to_string(player_chao_count) + "P)";
		}
	}
}

void update_chao_karate_rpc(discord::rich_presence& rpc) {
	// get 1p or 2p
	const int chao_karate_players =
		current_chao_area == chao_area::chao_karate ? 1 : 2;
	// data array does not seem to be set for karate, so use the object array
	const auto* const chao_object_array = &ChaoObjectArray;
	// if in match
	if (in_chao_karate_match()) {
		rpc.small_image_text = "";
		rpc.small_image_key = "chao_karate_icon";

		// if in single player karate append chao level and matches won
		if (chao_karate_players == 1) {
			rpc.large_image_text += " (";

			// if mods contains "Chao Karate: Buster's Tournament"
			if (mods.contains("Chao Karate: Buster's Tournament")) {
				rpc.large_image_text += chao_karate_level_name(
					chao_karate->level,
					true,
					chao_karate_busters_tournament_extra_mode,
					codes.contains(
						"Enable Encore Mode (After Completion of Regular Game)"
					)
				);
			}
			else {
				rpc.large_image_text +=
					chao_karate_level_name(chao_karate->level);
			}

			rpc.large_image_text += ", Matches Won: "
				+ std::to_string(chao_karate->matches_won) + ")";
		}
		// display both chao names
		if (ini::chao_names) {
			// go through each chao
			const std::size_t chao_count{ 2 };
			for (std::size_t chao_index{ 0 }; chao_index < chao_count; ++chao_index) {
				// get chao base
				const auto* const chao_base =
					chao_object_array[chao_index * 0x12]
						->Data1.Chao->ChaoDataBase_ptr;

				// get the chao name and decode it
				const auto name = decode_chao_name(*chao_base);
				// append it to rpc
				rpc.small_image_text += '`' + name + '`';

				// add seperator
				if (chao_index < chao_count - 1) {
					rpc.small_image_text += " vs. ";
				}
			}
		}
		// else, if in singleplayer karate, just display cpu name
		else if (chao_karate_players == 1) {
			rpc.small_image_text += " Vs. ";
			// get chao base
			const auto* const chao_base =
				chao_object_array[0x12]
					->Data1.Chao->ChaoDataBase_ptr;

			// get the chao name and decode it
			const auto name =
				decode_chao_name(*chao_base, true);

			// append it to rpc
			rpc.small_image_text += '`' + name + '`';
		}
		// else, if in multiplayer karate, just append Fighting Chao 2P
		else {
			rpc.small_image_text += "Fighting Chao 2P";
		}
	}
}

void update_chao_world_rpc(discord::rich_presence& rpc) {
	rpc.details = "Total Rings: " + std::to_string(TotalRings);

	switch (current_chao_area) {
	case chao_area::chao_race:
		update_chao_race_rpc(rpc);
		break;
	case chao_area::chao_race_entrance_2p:
		// hide sonic's smug face with 2p symbol, you aren't here sonic!
		rpc.small_image_key = "chao_race_icon";
		rpc.small_image_text = "Chao Race 2P";
		break;
	case chao_area::chao_karate_2p:
		rpc.small_image_key = "chao_karate_icon";
		rpc.small_image_text = "Chao Karate 2P";
	case chao_area::chao_karate:
		update_chao_karate_rpc(rpc);
		break;
	case chao_area::chao_lobby_alternative:
	case chao_area::chao_garden:
	case chao_area::hero_garden:
	case chao_area::dark_garden:
	case chao_area::chao_race_entrance:
	case chao_area::chao_kindergarten:
	case chao_area::chao_lobby:
	case chao_area::chao_stadium:
	case chao_area::chao_departure_machine:
		break;
	default:
		// unknown chao area, probably loading
		rpc = {};
	}
}
