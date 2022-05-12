#pragma once
#include <chrono>

// 60 fps
using frames = std::chrono::duration<long long, std::ratio<1, 60>>;
// system clock time point that stores times in frames (60ths of a second)
using time_point = std::chrono::time_point<std::chrono::system_clock, frames>;
