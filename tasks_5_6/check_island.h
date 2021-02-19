#ifndef CHECKISLAND_HEADER
#define CHECKISLAND_HEADER

#include <stdint.h>

uint16_t count_islands(uint8_t* mat, size_t rows, size_t cols, 
	bool all_dirs);

#endif
