#include "sa2_discord_rich_presence/free_cam.h"
#include "sa2_discord_rich_presence/clipboard.h"
#include "sa2_discord_rich_presence/level.h"
#include "sa2_discord_rich_presence/modding.h"
#include <UsercallFunctionHandler.h>
#include <numbers>
#include <sstream>

bool free_cam_enabled{ false };
bool freeze_time{ false };
struct free_cam free_cam{};
CameraParam* camera_param{ nullptr };
int camera_slot{};

NJS_VECTOR vector_rotation(float yaw, float pitch) {
	// convert yaw and pitch from degrees to radians
	yaw   *= std::numbers::pi_v<float> / 180.f;
	pitch *= std::numbers::pi_v<float> / 180.f;
	return {
		cos(yaw) * cos(pitch),
		sin(pitch),
		sin(yaw) * cos(pitch)
	};
}

NJS_VECTOR operator+(const NJS_VECTOR& lhs, const NJS_VECTOR& rhs) {
	return {
		lhs.x + rhs.x,
		lhs.y + rhs.y,
		lhs.z + rhs.z
	};
}

NJS_VECTOR operator*(const NJS_VECTOR& vector, const float scalar) {
	return {
		vector.x * scalar,
		vector.y * scalar,
		vector.z * scalar
	};
}

NJS_VECTOR cross(const NJS_VECTOR& lhs, const NJS_VECTOR& rhs) {
	return {
		lhs.y * rhs.z - lhs.z * rhs.y,
		lhs.z * rhs.x - lhs.x * rhs.z,
		lhs.x * rhs.y - lhs.y * rhs.x
	};
}

std::ostream& operator<<(std::ostream& os, const NJS_VECTOR& vector) {
	return os << "{ x: " << vector.x << ", y: " << vector.y
		<< ", z: " << vector.z << " }";
}

std::istream& operator>>(std::istream& is, NJS_VECTOR& vector) {
	std::string token;
	std::getline(is, token, ':');
	if (!(is >> vector.x)) {
		is.clear();
		is.ignore((std::numeric_limits<std::streamsize>::max()));
		return is;
	}
	std::getline(is, token, ':');
	if (!(is >> vector.y)) {
		is.clear();
		is.ignore((std::numeric_limits<std::streamsize>::max()));
		return is;
	}
	std::getline(is, token, ':');
	if (!(is >> vector.z)) {
		is.clear();
		is.ignore((std::numeric_limits<std::streamsize>::max()));
		return is;
	}
	std::getline(is, token, '}');
	return is;
}

std::istream& operator>>(std::istream& is, struct free_cam& free_cam) {
	std::string token;
	std::getline(is, token, ':');
	if (!(is >> free_cam.position)) {
		is.clear();
		is.ignore((std::numeric_limits<std::streamsize>::max()));
		return is;
	}
	std::getline(is, token, ':');
	if (!(is >> free_cam.yaw)) {
		is.clear();
		is.ignore((std::numeric_limits<std::streamsize>::max()));
		return is;
	}
	std::getline(is, token, ':');
	if (!(is >> free_cam.pitch)) {
		is.clear();
		is.ignore((std::numeric_limits<std::streamsize>::max()));
		return is;
	}
	return is;
}

// splitscreen mode before free_cam was activated
int splitscreen_mode_before{ 1 };

bool players_visible{ true };
void set_players_visibility(
	const bool visible, const bool change_value = true
) {
	if (change_value) {
		players_visible = visible;
	}
	for (std::size_t player_index{ 0 }; player_index < 2; ++player_index) {
		if (MainCharObj1[player_index] == nullptr) {
			continue;
		}
		auto& player = *MainCharObj1[player_index];
		if (visible) {
			// set player's scale to 1
			player.Scale = { 1.f, 1.f, 1.f };
		}
		else {
			// set player's scale to 0
			player.Scale = {};
		}
	}
}
void toggle_players_visibility() {
	set_players_visibility(!players_visible);
}

void enable_free_cam() {
	std::cout << "sa2-discord-rich-presence:\n";
	std::cout << "\tEnabling free cam\n";
	free_cam_enabled = true;
	// move to existing camera position

	constexpr auto word_to_deg = [](const WORD word) {
		return
			static_cast<float>(word) * (
				2.f * std::numbers::pi_v<float>
				/ std::numeric_limits<WORD>::max()
			) * 180.f / std::numbers::pi_v<float>;
	};

	// apply current camera location to our free_cam struct
	// (does index 0 mean player 0?)
	const auto& cam_loc = *pCameraLocations[0];
	free_cam.position = cam_loc.pos;
	free_cam.yaw = -90.f - word_to_deg(cam_loc.ang.y);
	free_cam.pitch = word_to_deg(cam_loc.ang.x);

	// set splitscreen mode
	splitscreen_mode_before = SplitscreenMode;
	SplitscreenMode = 1;
	// set player's visibility to value
	set_players_visibility(players_visible);

	// register custom camera
	camera_param = RegisterEventCameraFunc(
		0,
		[](CameraInfo* info, CameraParam* /*param*/) {
			// rotation
			constexpr auto deg_to_word = [](const float deg) {
				return static_cast<WORD>(
					std::numeric_limits<WORD>::max()
					* (deg * std::numbers::pi_v<float> / 180.f)
					/ (2.f * std::numbers::pi_v<float>)
				);
			};
			Rotation rotation{
				deg_to_word(free_cam.pitch),
				deg_to_word(-90.f - free_cam.yaw),
				0
			};

			// direction
			const auto direction =
				vector_rotation(free_cam.yaw, free_cam.pitch);
			// set camera location
			info->location = {
				free_cam.position,
				rotation,
				direction,
				free_cam.position + direction
			};
			// this allows camera location to be applied, however setting this
			// just once only works for a couple of seconds. perhaps another
			// enum value would be more appropriate, but I don't know it.
			SetAdjustMode(0, camera_slot, CameraAdjust::CameraAdjust_Three1);
		}
	);
	camera_slot = GetCurrentCameraSlot(0);
	boolCameraCollision = 0;
}

void disable_free_cam() {
	std::cout << "sa2-discord-rich-presence:\n";
	std::cout << "\tDisabling free cam\n";
	free_cam_enabled = false;
	// set splitscreen mode
	SplitscreenMode = splitscreen_mode_before;
	// set player's visibility to true without changing value
	// (value needed for enabling free cam again)
	set_players_visibility(true, false);

	ReleaseCamera(0, camera_slot);
}

bool is_free_cam_enabled() {
	return free_cam_enabled;
}

void toggle_free_cam() {
	if (is_free_cam_enabled()) {
		disable_free_cam();
	} else {
		enable_free_cam();
	}
}

// STOLEN FROM SA2 Debug Mode by Sora_yx
void __cdecl run_object_index_replacement(const int index) {
	if (freeze_time && index > 0) {
		return;
	}

	RunObjectIndex(index);
}

void update_free_cam_on_input() {
	if (ControllerPointers[0] == nullptr) {
		return;
	}
	const auto& controller = *ControllerPointers[0];
	const auto yaw_rotation =
		::vector_rotation(free_cam.yaw, 0.f);

	constexpr float left_stick_max{ 224.f };
	constexpr float right_stick_max{ 126.f };

	static float player_distance{ 32.f };

	// alternative controls (hold L + R) for extra functions
	if (
		(controller.on & Buttons::Buttons_L) != 0
		&& (controller.on & Buttons::Buttons_R) != 0
	) {
		// if start is pressed, load free cam from clipboard in format like:
		//   position: { x: 1.2, y: 2.3, z: 3.4 }
		//   yaw: 42
		//   pitch: 64
		if ((controller.press & Buttons::Buttons_Start) != 0) {
			std::cout << "sa2-discord-rich-presence:\n";
			std::cout << "\tupdate_free_cam_on_input():\n'";
			std::cout << "\t\ttrying to load free_cam from clipboard\n";
			std::istringstream clipboard{ read_clipboard() };
			clipboard >> free_cam;
		}
		// move player to camera position on dpad_down
		if ((controller.on & Buttons::Buttons_Down) != 0) {
			if (auto* const player = MainCharObj1[0]) {
				player->Position =
					free_cam.position + (yaw_rotation * player_distance);
			}
		}
	}
	else {
		// units/frame
		static float translation_speed{ 2.4f };
		// increase/decrease translation speed with dpad left and right
		if ((controller.press & Buttons::Buttons_Left) != 0) {
			translation_speed /= 1.5f;
		}
		if ((controller.press & Buttons::Buttons_Right) != 0) {
			translation_speed *= 1.5f;
		}
		// translate camera
		// (left stick (xz plane), A/B (y axis))
		// forward/backward
		free_cam.position = free_cam.position
			+ yaw_rotation
			* (
				translation_speed
				* static_cast<float>(-controller.y1)
				/ left_stick_max
			);
		// left/right
		free_cam.position = free_cam.position
			+ cross(yaw_rotation, NJS_VECTOR{ 0.f, 1.f, 0.f })
			* (
				translation_speed
				* static_cast<float>(controller.x1)
				/ left_stick_max
			);
		// up/down
		if ((controller.on & Buttons::Buttons_A) != 0) {
			free_cam.position.y += translation_speed;
		}
		if ((controller.on & Buttons::Buttons_B) != 0) {
			free_cam.position.y -= translation_speed;
		}

		// degrees/frame
		constexpr float rotation_speed{ 2.4f };
		// rotate camera
		// (right stick, snap to 15 degrees with X (yaw) and Y (pitch))
		free_cam.yaw += rotation_speed
			* static_cast<float>(controller.x2) / right_stick_max;
		free_cam.pitch += rotation_speed
			* static_cast<float>(controller.y2) / right_stick_max;

		if ((controller.press & Buttons::Buttons_X) != 0) {
			free_cam.yaw = std::round(free_cam.yaw / 15.f) * 15.f;
		}
		if ((controller.press & Buttons::Buttons_Y) != 0) {
			free_cam.pitch = std::round(free_cam.pitch / 15.f) * 15.f;
		}

		// toggle player's visibility on dpad down
		if ((controller.press & Buttons::Buttons_Down) != 0) {
			toggle_players_visibility();
		}

		// if start is pressed, output the camera position and rotation
		if ((controller.press & Buttons::Buttons_Start) != 0) {
			std::cout << "sa2-discord-rich-presence:\n";
			if (const auto current_level_name = ::current_level_name()) {
				std::cout <<
					"\tcurrent level: " << *current_level_name << '\n';
			}
			else {
				std::cout << "\tcurrent level: "
					<< std::to_string(+CurrentLevel) << "\n";
			}
			std::cout << "\tfree cam:\n";
			std::cout << "\t\tposition: " << free_cam.position << '\n';
			std::cout << "\t\tyaw: " << free_cam.yaw << '\n';
			std::cout << "\t\tpitch: " << free_cam.pitch << '\n';
		}
	}
}

void update_free_cam_on_frame() {
	if (free_cam_enabled) {
		// disable free cam on entering menu
		static auto game_state_before{ GameStates::GameStates_Inactive };
		if (
			game_state_before != GameStates::GameStates_Inactive
			&& GameState == GameStates::GameStates_Inactive
		) {
			disable_free_cam();
		}
		game_state_before = static_cast<GameStates>(GameState);
	}
}

void enable_freeze_time() {
	freeze_time = true;
}
void disable_freeze_time() {
	freeze_time = false;
}
bool is_freeze_time_enabled() {
	return freeze_time;
}
void toggle_freeze_time() {
	if (is_freeze_time_enabled()) {
		disable_freeze_time();
	}
	else {
		enable_freeze_time();
	}
}
void init_freeze_time() {
	write_call(0x43CF77, run_object_index_replacement);
}
