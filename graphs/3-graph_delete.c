#include "graphs.h"
#include <stdlib.h>


/**
* graph_delete - Deletes the entire graph, freeing all allocated memory for
* vertices and edges.
*
* @graph: Pointer to the graph structure to be deleted.
*/
void graph_delete(graph_t *graph)
{
	vertex_t *current_vertex = NULL;
	vertex_t *temp = NULL;

	/* Check if the graph pointer is valid */
	if (graph == NULL)
		return;

	/* Traverse the list of vertices and free each vertex */
	current_vertex = graph->vertices;
	while (current_vertex != NULL)
	{
		temp = current_vertex;
		current_vertex = current_vertex->next;
		free_vertex(temp);
	}

	/* Free the graph structure itself */
	free(graph);
}

/**
* free_edges - Frees the memory allocated for a linked list of edges.
*
* @edges: Pointer to the first edge in the linked list.
*/
void free_edges(edge_t *edges)
{
	edge_t *temp = NULL;

	/* Traverse the list of edges and free each edge */
	while (edges != NULL)
	{
		temp = edges;
		edges = edges->next;
		free(temp);
	}
}

/**
* free_vertex - Frees the memory allocated for a vertex, including its content
* and edges.
*
* @vertex: Pointer to the vertex to be freed.
*/
void free_vertex(vertex_t *vertex)
{
	/* Free the content of the vertex */
	free(vertex->content);
	/* Free the linked list of edges associated with the vertex */
	free_edges(vertex->edges);
	/* Free the vertex itself */
	free(vertex);
}
