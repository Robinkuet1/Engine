#pragma once
#include <string>

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
