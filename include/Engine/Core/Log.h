#pragma once

#include <iostream>
#include <cstring>

template<typename T, typename... Args>
static void log(T t, Args... args){
  std::cout << t << " ";
  if constexpr (sizeof...(args) > 0) {
    log(args...);
  }else {
      std::cout << "\n";
  }
}

#ifdef PLATFORM_WINDOWS
#define __FILENAME__ (strrchr(__FILE__, "\\\\") ? strrchr(__FILE__, "\\\\") + 1 : __FILE__)
#else
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#endif

#define LOG_ERROR(...) { log("\033[1;31m[ERROR]\033[0m", __FUNCTION__, "in", __FILENAME__, __VA_ARGS__); }
#define LOG_WARNING(...) { log("\033[1;33m[WARNING]\033[0m", __FUNCTION__, "in", __FILENAME__, __VA_ARGS__); }
#define LOG_INFO(...) { log("[INFO]", __VA_ARGS__); }
#define LOG_DEBUG(...) { log("\033[1;37m[DEBUG]\033[0m", __VA_ARGS__); }

#define ASSERT(cond) { if (!cond) { log("\033[1;31m[ASSERT FAILED]\033[0m", __FUNCTION__, "in", __FILENAME__, #cond, "failed"); } }