#include "pathfinding.h"

/**
* backtracking_graph - finds a path in the graph using backtracking
* @graph: the graph to navigate
* @start: the starting vertex
* @target: the target vertex
* Return: queue with the path to target
*/
queue_t *backtracking_graph(graph_t *graph, vertex_t const *start,
							vertex_t const *target)
{
	queue_t *Q;
	graph_t *visited;

	visited = graph_create();
	Q = queue_create();
	backtrack_find_path(graph, start, target, Q, visited);
	graph_delete(visited);
	if (!Q->front)
	{
		free(Q);
		return (NULL);
	}
	return (Q);
}

/**
* backtrack_find_path - recursively finds path in the graph using backtracking
* @graph: the graph to navigate
* @start: the starting vertex
* @target: the target vertex
* @path_queue: the queue to store the path
* @visited: the graph containing visited vertices
* Return: 1 if path is found, 0 otherwise
*/
int backtrack_find_path(graph_t *graph, vertex_t const *start,
						vertex_t const *target, queue_t *path_queue,
						graph_t *visited)
{
	edge_t *edge;

	printf("Checking %s\n", start->content);
	graph_add_vertex(visited, start->content, start->x, start->y);

	if (strcmp(target->content, start->content) == 0)
	{
		queue_push_front(path_queue, strdup(start->content));
		return (1);
	}

	edge = start->edges;
	while (edge)
	{
		if (!is_vertex_visited(edge->dest, visited))
		{
			if (backtrack_find_path(graph, edge->dest, target, path_queue, visited))
			{
				queue_push_front(path_queue, strdup(start->content));
				return (1);
			}
		}
		edge = edge->next;
	}
	return (0);
}

/**
* is_vertex_visited - checks if a vertex is in the visited graph
* @next: the vertex to check
* @visited: the graph containing visited vertices
* Return: 1 if vertex is visited, 0 otherwise
*/
int is_vertex_visited(const vertex_t *next, graph_t *visited)
{
	vertex_t *current_vertex;
	/* Iterate over visited vertices and check if the given vertex is visited */
	for (current_vertex = visited->vertices; current_vertex;
		current_vertex = current_vertex->next)
	{
/* printf("Comparing %s to %s\n", next->content, current_vertex->content); */
		if (strcmp(next->content, current_vertex->content) == 0)
			return (1);
	}
	return (0);
}

