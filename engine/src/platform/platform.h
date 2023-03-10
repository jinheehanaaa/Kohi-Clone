#pragma once

#include "defines.h"

// platform_state maintains state in decoupled way (ex: window handling)
typedef struct platform_state {
    void* internal_state;
} platform_state;

// platform_startup for platform startup
KAPI  b8 platform_startup(
    platform_state* plat_state,
    const char* application_name,
    i32 x,
    i32 y,
    i32 width,
    i32 height);

// platform_shutdown holds a pointer to platform state
KAPI void platform_shutdown(platform_state* plat_state);

// platform_pump_messages should continuously loop through application
KAPI b8 platform_pump_messages(platform_state* plat_state);

// Dealing with memory (platform specific)
void* platform_allocate(u64 size, b8 aligned);
void platform_free(void* block, b8 aligned);
void* platform_zero_memory(void* block, u64 size);
void* platform_copy_memory(void* dest, const void* source, u64 size);
void* platform_set_memory(void* dest, i32 value, u64 size);

// Color for log prompt
void platform_console_write(const char* message, u8 colour);
void platform_console_write_error(const char* message, u8 colour);

f64 platform_get_absolute_time();

// Sleep on the thread for the provided ms. This blocks the main thread.
// Should only be used for giving time back to the OS for unused update power.
// Therefore it is not exported.
void platform_sleep(u64 ms);