#pragma once
#include <string>
#include <memory>
#include "Log.h"

// Use these type instead of the normal ones for consistency.
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef char i8;
typedef short i16;
typedef int i32;
typedef long long i64;

typedef float f32;
typedef double f64;

// prefer string to char* when ever possible
typedef std::string string;

namespace std {
  template<typename... Args>
  string format(const string& format, Args... args) {
    const int size_s = std::snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
    if (size_s <= 0) { LOG_ERROR("Error during formatting."); }
    const auto size = static_cast<size_t>(size_s);
    const std::unique_ptr<char[]> buf(new char[size]);
    std::snprintf(buf.get(), size, format.c_str(), args...);
    return basic_string<char>(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
  }
}


/**
 * This enum is used to set the platform where this is running on.
 */
enum Platform : u8 { LINUX = 0, WINDOWS = 1, WEB = 2, UNKNOWN = 3 };

/**
 * Use this constexpr instead of Preprocessor Directives
 */
#if defined(__linux__)
constexpr Platform PLATFORM = LINUX;
#define PLATFORM_LINUX
#elif defined(_WIN32)
constexpr Platform PLATFORM = WINDOWS;
#define PLATFORM_WINDOWS
#elif defined(__EMSCRIPTEN__)
constexpr Platform PLATFORM = WEB;
#define PLATFORM_WEB
#else
constexpr Platform PLATFORM = UNKNOWN;
#endif
