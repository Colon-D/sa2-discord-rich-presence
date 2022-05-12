#pragma once
#include "sa2_discord_rich_presence/free_cam.h"
#include "sa2_discord_rich_presence/modding.h"
#include <iostream>
#include <string>

// yet another free cam, hidden inside of this rpc mod

// free cam I made for taking screenshots of the game.
// not to be confused with kellsnc's Free Cam mod, which - as of now - released
// four hours ago.
// this is my own free cam mod, which I used to take screenshots, it has been
// updated to try and use the latest functions and values in the mod loader.
// you can fly around, save and load location, move the player etc...
// sometimes it doesn't work, but it's better than nothing.

// why? I wanted some features other free cams did not have, and controls that 
// I could choose that I liked.

// controls:
//   debug mode enabled:
//     toggle free cam: L + R + dpad up
//     toggle freeze: L + R + dpad left
//     load a cutscene from index in clipboard (only works in level and once):
//       L + R + dpad right
//     free cam enabled:
//       translate camera:                   left stick / A / B
//       rotate camera:                      right stick
//       snap camera rotation to 15 degrees: X / Y
//       toggle player visibility:           dpad down
//       log camera position + rotation:     start
//       read camera position from clipboard:
//         input: L + R + start
//         format like:
//           position: { x: 1.2, y: 2.3, z: 3.4 }
//           yaw: 42
//           pitch: 64
//       move player to camera position (useful for loading objects):
//         L + R + dpad down

struct free_cam {
	NJS_VECTOR position{};
	/// degrees
	float yaw{};
	/// degrees
	float pitch{};
};

// NJS_VECTOR operations, I am sure these exist in the engine, but I can't be
// bothered to find them

/// returns a unit vector from a yaw and a pitch (in degrees)
/// \param yaw degrees
/// \param pitch degrees
NJS_VECTOR vector_rotation(float yaw, float pitch);

NJS_VECTOR operator+(const NJS_VECTOR& lhs, const NJS_VECTOR& rhs);

NJS_VECTOR operator*(const NJS_VECTOR& vector, float scalar);

NJS_VECTOR cross(const NJS_VECTOR& lhs, const NJS_VECTOR& rhs);

// ostream operator for vector formatted like: { x: 1.2, y: 2.3, z: 3.4 }
std::ostream& operator<<(std::ostream& os, const NJS_VECTOR& vector);

// istream operator for vector formatted like: { x: 1.2, y: 2.3, z: 3.4 }
std::istream& operator>>(std::istream& is, NJS_VECTOR& vector);

// istream operator for free cam formatted like:
//   position: { x: 1.2, y: 2.3, z: 3.4 }
//   yaw: 42
//   pitch: 64
std::istream& operator>>(std::istream& is, free_cam& free_cam);

extern free_cam free_cam;

void enable_free_cam();
void disable_free_cam();
bool is_free_cam_enabled();
void toggle_free_cam();
/// updates free_cam instance based on input, you can choose to instead
/// manually update the free_cam instance if you want your own input, but hey,
/// this is not a camera mod!
void update_free_cam_on_input();
/// disables free_cam on exiting level
void update_free_cam_on_frame();

void enable_freeze_time();
void disable_freeze_time();
bool is_freeze_time_enabled();
void toggle_freeze_time();
void init_freeze_time();
