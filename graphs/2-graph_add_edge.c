#include "graphs.h"
#include <stdio.h>

int add_directed_edge(vertex_t *src_vertex, vertex_t *dest_vertex)
{
	/* Create an edge from src to dest */
	edge_t *src_edge = malloc(sizeof(edge_t));

	if (src_edge == NULL)
		return (0);

	src_edge->dest = dest_vertex;
	src_edge->next = NULL;

	if (src_vertex->edges == NULL)
		src_vertex->edges = src_edge;
	else
	{
		edge_t *temp = src_vertex->edges;

		while (temp->next != NULL)
			temp = temp->next;
		temp->next = src_edge;
	}

	src_vertex->nb_edges++;

	return (1);
}


int graph_add_edge(graph_t *graph, const char *src, const char *dest,
					edge_type_t type)
{
	if (graph == NULL || src == NULL || dest == NULL)
		return (0);

	/* Find the source and destination vertices */
	vertex_t *src_vertex = NULL;
	vertex_t *dest_vertex = NULL;
	vertex_t *current_vertex = NULL;

	current_vertex = graph->vertices;

	while (current_vertex != NULL)
	{
		if (strcmp(current_vertex->content, src) == 0)
			src_vertex = current_vertex;
		if (strcmp(current_vertex->content, dest) == 0)
			dest_vertex = current_vertex;

		current_vertex = current_vertex->next;
	}

	/* Check if the source and destination vertices are found */
	if (src_vertex == NULL || dest_vertex == NULL)
		return (0);

	/* Add edge from src to dest */
	if (!add_directed_edge(src_vertex, dest_vertex))
		return (0);

	/* If BIDIRECTIONAL, add edge from dest to src */
	if (type == BIDIRECTIONAL)
	{
		if (!add_directed_edge(dest_vertex, src_vertex))
		{
			/* Revert changes in case of error*/
			src_vertex->nb_edges--;
			free(src_vertex->edges);
			return (0);
		}
	}
	return (1);
}
