#pragma once

#define BIT(x) (1 << x)

#define GLORY_API
// this should the export of the symboles in so files
#ifdef GLORY_PLATFORM_LINUX
#ifdef GLORY_BUILD_SHARED
#define GLORY_API __attribute__((visibility("default")))
#else
#define GLORY_API
#endif
#endif

// export symbole shared dll
#ifdef GLORY_PLATFORM_WINDOWS
#ifdef GLORY_BUILD_DLL
#define GLORY_API __declspec(dllexport)
#else
#define GLORY_API __declspec(dllimport)
#endif
#endif
