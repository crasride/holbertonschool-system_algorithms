#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


/**
* bfs_traverse_from_vertex - Performs a breadth-first traversal on a graph
* starting from a given vertex.
* @graph: Pointer to the graph to traverse.
* @start_vertex: Pointer to the starting vertex for the traversal.
* @visited: Array to keep track of visited vertices.
* @action: Pointer to the action function called for each visited vertex.
* @max_depth: Pointer to the value of the maximum depth reached during the
* traversal.
*/
void bfs_traverse_from_vertex(const graph_t *graph,
									vertex_t *start_vertex,
									int *visited,
									void (*action)(const vertex_t *v,
									size_t depth), size_t *max_depth)
{
	vertex_t *current_vertex = NULL;
	size_t depth;
	size_t front, rear;
	edge_t *edge = NULL;
	vertex_t **queue = malloc(graph->nb_vertices * sizeof(vertex_t *));

	if (queue == NULL)
		return;

	front = 0, rear = 0;

	queue[rear] = start_vertex;
	visited[start_vertex->index] = 1; /* Mark the starting vertex as visited */

	while (front <= rear)
	{
		current_vertex = queue[front];
		depth = visited[current_vertex->index] - 1;

		if (depth > *max_depth)
			*max_depth = depth; /* Update the maximum depth if needed */

		action(current_vertex, depth);

		edge = current_vertex->edges;
		/* Iterate through the edges of the current vertex */
		while (edge != NULL)
		{
			if (!visited[edge->dest->index])
			{
				queue[++rear] = edge->dest;/* Enqueue the destination vertex */
				/* Mark the destination as visited */
				visited[edge->dest->index] = depth + 2;
			}
			edge = edge->next;
		}
		front++; /* Dequeue the current vertex */
	}

	free(queue);
}

/**
* breadth_first_traverse - Performs a breadth-first traversal on a graph.
* @graph: Pointer to the graph to traverse.
* @action: Pointer to the action function called for each visited vertex.
* Return: The maximum depth reached during the traversal or 0 on failure.
*/
size_t breadth_first_traverse(const graph_t *graph,
								void (*action)(const vertex_t *v, size_t depth))
{
	vertex_t *current_vertex = NULL;
	int *visited = NULL;
	size_t max_depth = 0;

	if (graph == NULL || action == NULL)
		return (0);

	visited = calloc(graph->nb_vertices, sizeof(int));
	if (visited == NULL)
		return (0);

	current_vertex = graph->vertices;

	/* Check if there are no edges in the graph */
	if (current_vertex != NULL && current_vertex->edges == NULL)
	{
		action(current_vertex, 0);
		free(visited);
		return (0);
	}
	/* Traverse the graph starting from each unvisited vertex */
	while (current_vertex != NULL)
	{
		if (!visited[current_vertex->index])
			bfs_traverse_from_vertex(graph, current_vertex, visited,
			action, &max_depth);

		current_vertex = current_vertex->next;
	}

	free(visited);

	return (max_depth);
}
