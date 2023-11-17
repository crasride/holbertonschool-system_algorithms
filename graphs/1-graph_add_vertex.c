#include "graphs.h"
#include <stdio.h>

/**
* create_vertex - Creates and initializes a new vertex with the given content
* and index.
*
* @str: The content of the new vertex.
* @index: The index of the new vertex.
* Return: A pointer to the newly created vertex, or NULL if memory allocation
*         or string duplication fails.
*/
vertex_t *create_vertex(const char *str, int index)
{
	vertex_t *new_vertex = malloc(sizeof(vertex_t));

	if (new_vertex == NULL)
		/* Memory allocation failed */
		return (NULL);

	/* Initialize the new vertex */
	new_vertex->index = index;
	new_vertex->content = strdup(str);
	if (new_vertex->content == NULL)
	{
		free(new_vertex);
		/* String duplication failed */
		return (NULL);
	}
	new_vertex->nb_edges = 0;
	new_vertex->edges = NULL;
	new_vertex->next = NULL;

	return (new_vertex);
}

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
	vertex_t *current_vertex, *new_vertex;

		if (graph == NULL || str == NULL)
		return (NULL);

	/* Check if the vertex with the same content already exists */
	current_vertex = graph->vertices;

	while (current_vertex != NULL)
	{
		if (strcmp(current_vertex->content, str) == 0)
			/* Vertex with the same content already exists */
			return (NULL);
		current_vertex = current_vertex->next;
	}

	/* Create a new vertex */
	new_vertex = create_vertex(str, graph->nb_vertices);

	if (new_vertex == NULL)
		/* Vertex creation failed */
		return (NULL);

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

	return (new_vertex);
}
