#include "graphs.h"
#include <stdio.h>


/**
* add_directed_edge -Adds a directed edge from the source vertex to the
* destination vertex.
*
* @src_vertex: Pointer to the source vertex.
* @dest_vertex: Pointer to the destination vertex.
* Return: 1 if the directed edge is successfully added, 0 otherwise.
*/
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

/**
* graph_add_edge - Adds an edge between two vertices to an existing graph.
*
* @graph: Pointer to the graph to add the edge to.
* @src: The string identifying the vertex to make the connection from.
* @dest: The string identifying the vertex to connect to.
* @type: The type of edge (UNIDIRECTIONAL or BIDIRECTIONAL).
*
* Return: 1 on success, 0 on failure. On failure, no edge must be created,
*         and there must be no memory leak.
*         If either src or dest are not found in any vertex of graph,
*         the function must fail, and there must be no leak.
*/
int graph_add_edge(graph_t *graph, const char *src, const char *dest,
					edge_type_t type)
{
	/* Find the source and destination vertices */
	vertex_t *src_vertex = NULL;
	vertex_t *dest_vertex = NULL;
	vertex_t *current_vertex = NULL;

	if (graph == NULL || src == NULL || dest == NULL)
		return (0);

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
