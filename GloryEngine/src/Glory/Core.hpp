#pragma once

#define BIT(x) (1 << x)

//#define GLORY_API

// this should the export of the symboles in so files
#ifdef GLORY_PLATFORM_LINUX
#ifdef GLORY_BUILD_SHARED
#define GLORY_API __attribute__((visibility("default")))
#else
#define GLORY_API
#endif
#endif

#ifndef GLORY_ENABLE_ASSERT
#define GLORY_ASSERT(x, ...)                \
    {                                       \
        if (!(x))                             \
        {                                   \
            GLORY_CLIENT_ERROR(__VA_ARGS__) \
            __builtin_trap();               \
        }                                   \
    }
#define GLORY_CORE_ASSERT(x, ...)          \
    {                                      \
        if (!(x))                            \
        {                                  \
            GLORY_CORE_ERROR(__VA_ARGS__); \
            __builtin_trap();              \
        }                                  \
    }
#else
#define GLORY_ASSERT(x, ...)
#define GLORY_CORE_ASSERT(x, ...)
#endif

// export symbole shared dll
#ifdef GLORY_PLATFORM_WINDOWS
#ifdef GLORY_BUILD_DLL
#define GLORY_API __declspec(dllexport)
#else
#define GLORY_API __declspec(dllimport)
#endif
#endif
