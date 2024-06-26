#pragma once

#include "../tock.h"
#include "syscalls/humidity_syscalls.h"

#ifdef __cplusplus
extern "C" {
#endif

// Function signature for humidity data callback.
//
// - `arg1` (`int`): Returncode indicating status from sampling the sensor.
// - `arg2` (`int`): Humidity in hundredths of percent.
typedef void (*libtock_humidity_callback)(returncode_t, int);

// Start a humidity measurement. The reading will be provided via the callback.
returncode_t libtock_humidity_read(libtock_humidity_callback cb);

#ifdef __cplusplus
}
#endif
