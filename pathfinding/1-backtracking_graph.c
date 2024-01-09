#include "pathfinding.h"

/**
 * visited_path - checks if a vertex is in the visited graph
 * @next: the vertex to check
 * @visited: the graph containing visited vertices
 * Return: 1 if vertex is visited, 0 otherwise
 */
int visited_path(vertex_t *next, graph_t *visited)
{
	size_t i;
	vertex_t *temp;

	temp = visited->vertices;
	for (i = 0; i < visited->nb_vertices; i++)
	{
		if (strcmp(next->content, temp->content) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

/**
 * find_graph_path - recursively finds a path in the graph using backtracking
 * @graph: the graph to navigate
 * @start: the starting vertex
 * @target: the target vertex
 * @Q: the queue to store the path
 * @visited: the graph containing visited vertices
 * Return: 1 if path is found, 0 otherwise
 */
int find_graph_path(graph_t *graph, vertex_t const *start,
					vertex_t const *target, queue_t *Q, graph_t *visited)
{
	edge_t *edge;

	printf("Checking %s\n", start->content);
	graph_add_vertex(visited, start->content, start->x, start->y);

	if (strcmp(target->content, start->content) == 0)
	{
		queue_push_front(Q, strdup(start->content));
		return (1);
	}

	edge = start->edges;
	while (edge)
	{
		if (!visited_path(edge->dest, visited))
		{
			if (find_graph_path(graph, edge->dest, target, Q, visited))
			{
				queue_push_front(Q, strdup(start->content));
				return (1);
			}
		}
		edge = edge->next;
	}
	return (0);
}

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
	find_graph_path(graph, start, target, Q, visited);
	graph_delete(visited);
	if (!Q->front)
	{
		free(Q);
		return (NULL);
	}
	return (Q);
}

