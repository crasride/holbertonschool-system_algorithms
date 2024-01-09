#include "pathfinding.h"

/**
* point_push - adds a point to the queue
* @path: queue to store the path
* @x: x coordinate
* @y: y coordinate
* Return: 1 if success, 0 if failure
*/
int point_push(queue_t **path, int x, int y)
{
	point_t *new = malloc(sizeof(point_t));

	if (!new)
		return (0);
	new->x = x;
	new->y = y;
	queue_push_front(*path, new);
	return (1);
}

/**
* recursive_backtracker - recursive backtracking algorithm
* @path: queue to store the path
* @visited: 2D array of ints to mark visited cells
* @map: 2D array of chars representing the maze
* @rows: number of rows
* @cols: number of columns
* @start: starting point
* @x: current x coordinate
* @y: current y coordinate
* @target: target point
* @moves: array of possible moves
* Return: 1 if target reached, 0 if not
*/
int recursive_backtracker(queue_t **path, int **visited, char **map, int rows,
							int cols, point_t const *start,
							int x, int y, point_t const *target, point_t *moves)
{
	int i;

	if (x >= cols || y >= rows /* check if inside map (right and bottom) */
			|| x < 0 || y < 0 /* check if inside map (left and top) */
			|| map[y][x] == '1' /* check if wall */
			|| visited[y][x] == 1) /* check if visited */
		return (0);

	printf("Checking coordinates [%d, %d]\n", x, y);
	if (x == target->x && y == target->y) /* check if target reached */
		return (point_push(path, x, y));
	visited[y][x] = 1; /* mark as visited */

	/* check all directions - if one is possible: add to queue */
	for (i = 0; i < 4; ++i)
	{
		if (recursive_backtracker(path, visited, map, rows, cols, start,
								x + moves[i].x, y + moves[i].y, target, moves))
			return (point_push(path, x, y));
	}
	/* else back to previous */
	return (0);
}

/**
* create_map - creates a 2D array of ints
* @rows: number of rows
* @cols: number of columns
* Return: pointer to the array
*/
int **create_map(int rows, int cols)
{
	int i, j;
	int **map = malloc(sizeof(int *) * rows);

	if (!map)
		return (NULL);
	for (i = 0; i < rows; ++i)
	{
		map[i] = malloc(sizeof(int) * cols);
		if (!map[i])
		{
			for (j = 0; j < i; ++j)
				free(map[j]);
			free(map);
			return (NULL);
		}
		/* init map to 0 */
		for (j = 0; j < cols; ++j)
			map[i][j] = 0;
	}
	return (map);
}

/**
* backtracking_array - backtracking algorithm using an array
* @map: 2D array of chars representing the maze
* @rows: number of rows
* @cols: number of columns
* @start: starting point
* @target: target point
* Return: queue containing the path, NULL if failed
*/
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target)
{
	int i = 0, ret_val;
	int **visited = NULL;
	queue_t *path = NULL;
	point_t RIGHT = {1, 0}, BOTTOM = {0, 1}, LEFT = {-1, 0}, TOP = {0, -1};
	point_t *moves = malloc(sizeof(point_t *) * 4);

	if (!moves)
		return (NULL);
	moves[0] = RIGHT;
	moves[1] = BOTTOM;
	moves[2] = LEFT;
	moves[3] = TOP;

	if (!map || !*map || !rows || !cols || !start || !target)
		return (NULL);

	visited = create_map(rows, cols);

	path = queue_create();
	/* erase all if failed */
	if (!path)
	{
		for (i = 0; i < rows; i++)
			free(visited[i]);
		free(visited);
		return (NULL);
	}

	ret_val = recursive_backtracker(&path, visited, map, rows, cols, start,
									start->x, start->y, target, moves);
	if (!ret_val)
	{
		queue_delete(path);
		path = NULL;
	}
	for (i = 0; i < rows; i++)
		free(visited[i]);
	free(visited);
	free(moves);
	return (path);
}
