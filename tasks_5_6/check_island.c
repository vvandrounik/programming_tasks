#include "check_island.h"

typedef struct pair
{
	int8_t first;
	int8_t second;
} pair_t;

//top, right, bottom, left 
static pair_t hv_dirs[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

//top, right, bottom, left
//top right, bottom right, bottom left, top left
static pair_t chv_dirs[] = {
	{-1, 0}, {0, 1}, {1, 0}, {0, -1},
	{-1, 1}, {1, 1}, {1, -1}, {-1, -1}
};

static void fill_island(uint8_t* mat,
	size_t rows, size_t cols,
	pair_t* dirs, size_t dirs_size,
	size_t i, size_t j)
{
	if (mat[i * cols + j] != 1)
		return;
	
	mat[i * cols + j] = 0;

	for (size_t k = 0; k < dirs_size; ++k)
	{
		size_t ni = i + dirs[k].first;
		size_t nj = j + dirs[k].second;

		if (ni >= 0 && ni < rows &&
			nj >= 0 && nj < cols)
		{
			fill_island(mat, rows, cols, 
						dirs, dirs_size, 
						ni, nj);
		}
	}
}

uint16_t count_islands(uint8_t* mat, size_t rows, size_t cols, 
	bool all_dirs)
{
	uint16_t islands_count = 0;

	pair_t* dirs = all_dirs ? chv_dirs : hv_dirs;
	size_t dirs_size = all_dirs 
		? sizeof(chv_dirs) / sizeof(chv_dirs[0]) 
		: sizeof(hv_dirs) / sizeof(hv_dirs[0]);

	for (size_t i = 0; i < rows; ++i)
	{
		for (size_t j = 0; j < cols; ++j)
		{
			if (mat[i * cols + j] != 0)
			{
				++islands_count;
				fill_island(mat, rows, cols,
							dirs, dirs_size,
							i, j);
			}
		}
	}

	return islands_count;
}