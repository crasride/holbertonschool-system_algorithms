#include "graphs.h"
#include <stdio.h>


/**
* depth_first_traverse - Goes through a graph using the depth-first algorithm
* @graph: Pointer to the graph to traverse
* @action: Pointer to a function to be called for each visited vertex
* Return: The biggest vertex depth or 0 on failure
*/
size_t depth_first_traverse(const graph_t *graph,
							void (*action)(const vertex_t *v, size_t depth))
{
	size_t depth = 0;
	int *visited = NULL;

	if (graph == NULL || action == NULL)
		return (0);

	visited = calloc(graph->nb_vertices, sizeof(int));
	if (visited == NULL)
		return (0);

	depth = depth_first_traverse_helper(graph->vertices, action, 0, visited);

	free(visited);

	return (depth);
}

/**
* depth_first_traverse_helper - Recursive function for depth-first traversal
* @vertex: Pointer to the current vertex
* @action: Pointer to a function to be called for each visited vertex
* @depth: Current depth
* @visited: Array to track visited vertices
* Return: The biggest vertex depth
*/
size_t depth_first_traverse_helper(const vertex_t *vertex,
									void (*action)(const vertex_t *v,
									size_t depth), size_t depth, int *visited)
{
	edge_t *edge = NULL;
	size_t max_depth = depth;

	if (vertex == NULL || visited[vertex->index] == 1)
		return (0);

	visited[vertex->index] = 1;

	action(vertex, depth);

	edge = vertex->edges;
	while (edge != NULL)
	{
		if (visited[edge->dest->index] == 0)
		{
			size_t current_depth = depth_first_traverse_helper(edge->dest,
			action, depth + 1, visited);
			max_depth = (current_depth > max_depth) ? current_depth : max_depth;
		}
		edge = edge->next;
	}

	return (max_depth);
}


