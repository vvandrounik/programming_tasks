#ifndef CHECKISLAND_HEADER
#define CHECKISLAND_HEADER

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

uint16_t count_islands(uint8_t* mat, size_t rows, size_t cols,
		bool all_dirs);

#ifdef __cplusplus
}
#endif

#endif
