#include "graphs.h"
#include <stdlib.h>



void graph_delete(graph_t *graph)
{
	vertex_t *current_vertex = NULL;
	vertex_t *temp = NULL;

	if (graph == NULL)
		return;

	current_vertex = graph->vertices;
	while (current_vertex != NULL)
	{
		temp = current_vertex;
		current_vertex = current_vertex->next;
		free_vertex(temp);
	}

	free(graph);
}


void free_edges(edge_t *edges)
{
	edge_t *temp = NULL;

	while (edges != NULL)
	{
		temp = edges;
		edges = edges->next;
		free(temp);
	}
}

void free_vertex(vertex_t *vertex)
{
	free(vertex->content);
	free_edges(vertex->edges);
	free(vertex);
}

