#include "calc_volume.h"
#include "priority_queue.h"

#include <stdbool.h>
#include <stdlib.h>

typedef struct pair
{
	int8_t first;
	int8_t second;
} pair_t;


//top, right, bottom, left 
static pair_t hv_dirs[] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} };

typedef struct cell
{
	size_t i;
	size_t j;
	int height;
} cell_t;

static int cmp(void* a, void* b)
{
	return ((cell_t*)a)->height - ((cell_t*)b)->height;
}

int calc_volume(int* mat, size_t rows, size_t cols)
{
	bool* visited = (bool*)calloc(rows * cols, sizeof(bool));

	priority_queue_t* queue = NULL;
	create(&queue, cmp);

	for (size_t i = 0; i < rows; ++i)
	{
		visited[i * cols] = true;
		cell_t* cell = (cell_t*)malloc(sizeof(cell_t));
		cell->height = mat[i * cols];
		cell->i = i;
		cell->j = 0;
		push(queue, cell);

		visited[i * cols + (cols - 1)] = true;
		cell = (cell_t*)malloc(sizeof(cell_t));
		cell->height = mat[i * cols + (cols - 1)];
		cell->i = i;
		cell->j = cols - 1;
		push(queue, cell);
	}

	for (size_t j = 0; j < cols; ++j)
	{
		visited[j] = true;
		visited[(rows - 1) * cols + j] = true;

		cell_t* cell = (cell_t*)malloc(sizeof(cell_t));
		cell->height = mat[j];
		cell->i = 0;
		cell->j = j;
		push(queue, cell);

		cell = (cell_t*)malloc(sizeof(cell_t));
		cell->height = mat[(rows - 1) * cols + j];
		cell->i = rows - 1;
		cell->j = j;
		push(queue, cell);
	}

	int volume = 0;
	size_t dirs_size = sizeof(hv_dirs) / sizeof(hv_dirs[0]);

	while (top(queue) != NULL)
	{
		cell_t* cell = (cell_t*)top(queue);
		pop(queue);

		for (size_t k = 0; k < dirs_size; ++k)
		{
			size_t ni = cell->i + hv_dirs[k].first;
			size_t nj = cell->j + hv_dirs[k].second;

			if (ni > 0 && ni < rows - 1 &&
				nj > 0 && nj < cols - 1 &&
				!visited[ni * cols + nj])
			{		
				cell_t* ncell = (cell_t*)malloc(sizeof(cell_t));
				ncell->i = ni;
				ncell->j = nj;

				if (mat[ni * cols + nj] < cell->height) {
					volume += cell->height - mat[ni * cols + nj];
					ncell->height = __max(mat[ni * cols + nj], cell->height);
				}

				push(queue, ncell);
				visited[ni * cols + nj] = true;
			}
		}

		free(cell);
	}

	destroy(queue);
	return volume;
}
