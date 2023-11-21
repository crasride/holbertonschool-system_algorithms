#include "graphs.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void bfs_traverse_from_vertex(const graph_t *graph,
									vertex_t *start_vertex,
									int *visited,
									void (*action)(const vertex_t *v,
									size_t depth), size_t *max_depth)
{
	vertex_t *current_vertex = NULL;
	size_t depth, front, rear;
	edge_t *edge = NULL;
	vertex_t **queue = malloc(graph->nb_vertices * sizeof(vertex_t *));

	if (queue == NULL)
		return;

	front = 0, rear = 0;

	queue[rear] = start_vertex;
	visited[start_vertex->index] = 1;

	while (front <= rear)
	{
		current_vertex = queue[front];
		depth = visited[current_vertex->index] - 1;

		if (depth > *max_depth)
			*max_depth = depth;

		action(current_vertex, depth);
		edge = current_vertex->edges;

		while (edge != NULL)
		{
			if (!visited[edge->dest->index])
			{
				queue[++rear] = edge->dest;
				visited[edge->dest->index] = depth + 2;
			}
			edge = edge->next;
		}
		front++;
	}
	free(queue);
}


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

	while (current_vertex != NULL)
	{
		if (!visited[current_vertex->index])
			bfs_traverse_from_vertex(graph, current_vertex, visited, action,
									&max_depth);

		current_vertex = current_vertex->next;
	}

	free(visited);

	return (max_depth);
}


