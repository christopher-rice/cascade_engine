#pragma once

// Shortened names for unsigned int types
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

// Shortened names for signed int types
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

// Shortened names for float types
typedef float f32;
typedef double f64;

// Shortened names for Boolean types
typedef int b32;
typedef char b8;

// Properly defines static assertions 
// Behaves differently for clang and gcc than with other compilers
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

// Ensures all types are the correct size
STATIC_ASSERT(sizeof(u8) == 1, "Expected u8 to be 1 byte.");
STATIC_ASSERT(sizeof(u16) == 2, "Expected u8 to be 2 byte.");
STATIC_ASSERT(sizeof(u32) == 4, "Expected u8 to be 4 byte.");
STATIC_ASSERT(sizeof(u64) == 8, "Expected u8 to be 8 byte.");

STATIC_ASSERT(sizeof(i8) == 1, "Expected i8 to be 1 byte.");
STATIC_ASSERT(sizeof(i16) == 2, "Expected i16 to be 2 byte.");
STATIC_ASSERT(sizeof(i32) == 4, "Expected i32 to be 4 byte.");
STATIC_ASSERT(sizeof(i64) == 8, "Expected i64 to be 8 byte.");

STATIC_ASSERT(sizeof(f32) == 4, "Expected f32 to be 4 byte.");
STATIC_ASSERT(sizeof(f64) == 8, "Expected f64 to be 8 byte.");

// Macros for true and false values
#define TRUE 1
#define FALSE 0

// Checking which platform engine is being ran on
// Is Windows platform
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__)
#define KPLATFORM_WINDOWS 1
// Checks if Windows supports 64-bit
#ifndef _WIN64
#error "64-bit is required on Windows!"
#endif
// Is Linux OS
#elif defined(__linux__) || defined(__gnu_linux__)
#define KPLATFORM_LINUX 1
// Is Android
#if defined(__ANDROID__)
#define KPLATFORM_ANDROID 1
#endif
// Is other version of Linux
#elif defined(__unix__)
#define KPLATFORM_UNIX 1
// Is Posix
#elif defined(_POSIX_VERSION)
#define KPLATFORM_POSIX 1
// Is Apple device
#elif __APPLE__
#define KPLATFORM_APPLE 1
#include <TargetConditionals.h>
// Is IPhone simulator
#if TARGET_IPHONE_SIMULATOR
#define KPLATFORM_IOS 1
#define KPLATFORM_IOS_SIMULATOR 1
// Is IPhone
#elif TARGET_OS_IPHONE
#define KPLATFROM_IOS 1
// Is Mac
#elif TARGET_OS_MAC
// Is unknown Apple platform
#else
#error "Unknown Apple platform"
#endif
// Is unknown platform
#else
#error "Unknown platform!"
#endif

// Handles function importing and exporting
// Check if function exports
#ifdef KEXPORT
#ifdef _MSC_VER
#define KAPI __declspec(dllexport)
#else
#define KAPI __attribute__((visibility("default")))
#endif
// Checks if function imports
#else
#ifdef _MSC_VER
#define KPAI __declspec(dllimport)
#else
#define KAPI
#endif
#endif