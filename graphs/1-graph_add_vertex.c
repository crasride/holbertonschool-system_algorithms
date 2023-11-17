#include "graphs.h"
#include <stdio.h>

/**
 * graph_add_vertex - Adds a vertex to an existing graph.
 *
 * @graph: Pointer to the graph to add the vertex to.
 * @str: The string to store in the new vertex.
 *
 * Return: Pointer to the created vertex, or NULL on failure.
 *         If a vertex in the graph already stores the string str,
 *         the function must fail, and there must be no leak.
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	if (graph == NULL || str == NULL)
		return NULL;

	/* Check if the vertex with the same content already exists */
	vertex_t *current_vertex = graph->vertices;
	while (current_vertex != NULL)
	{
		if (strcmp(current_vertex->content, str) == 0)
			return NULL;  /* Vertex with the same content already exists */
		current_vertex = current_vertex->next;
	}

	/* Create a new vertex */
	vertex_t *new_vertex = malloc(sizeof(vertex_t));
	if (new_vertex == NULL)
		return NULL;  /* Memory allocation failed */

	/* Initialize the new vertex */
	new_vertex->index = graph->nb_vertices;
	new_vertex->content = strdup(str);
	if (new_vertex->content == NULL)
	{
		free(new_vertex);
		return NULL;  /* String duplication failed */
	}
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;
	new_vertex->next = NULL;

	/* Add the new vertex to the graph */
	if (graph->vertices == NULL)
		graph->vertices = new_vertex;
	else
	{
		current_vertex = graph->vertices;
		while (current_vertex->next != NULL)
			current_vertex = current_vertex->next;
		current_vertex->next = new_vertex;
	}

	/* Increment the number of vertices in the graph */
	graph->nb_vertices++;

	return new_vertex;
}
