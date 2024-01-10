#ifndef __PATHFINDER__
#define __PATHFINDER__


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <sys/types.h>
#include "queues.h"
#include "graphs.h"

/**
* struct point_s - Structure storing coordinates
*
* @x: X coordinate
* @y: Y coordina
*
*/
typedef struct point_s
{
	int x;
	int y;
} point_t;

/*Functions task 0*/
queue_t *backtracking_array(char **map, int rows, int cols,
							point_t const *start, point_t const *target);

/*Functions task 1*/
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target);
int backtrack_find_path(graph_t *graph, vertex_t const *start,
						vertex_t const *target, queue_t *path_queue,
						graph_t *visited);
int is_vertex_visited(const vertex_t *next, graph_t *visited);

/*Functions task 2*/
/**
* struct DijkstraData - data for Dijkstra's algorithm
*
* @distance: array of distances from start vertex
* @from: array of previous vertices in path
* @verts: array of pointers to vertices
*
*/
typedef struct DijkstraData
{
	int *distance; /* distance from start vertex */
	vertex_t **from; /* previous vertex in path */
	vertex_t **verts; /* array of pointers to vertices */
} DijkstraData;

queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target);

#endif /* __PATHFINDER__ */
