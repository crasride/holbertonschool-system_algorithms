#include "pathfinding.h"


/**
* cleanup_memory - frees memory allocated for DijkstraData
* @data: pointer to DijkstraData struct
*/
void cleanup_memory(DijkstraData *data)
{
	free(data->distance);
	free(data->from);
	free(data->verts);
}

/**
* safe_strdup - duplicates a string
* @s: string to duplicate
* Return: pointer to new string
*/
char *safe_strdup(const char *s)
{
	char *str = strdup(s);

	if (!str)
	{
		perror("Error duplicating string");
		exit(EXIT_FAILURE);
	}
	return (str);
}

/**
* initialize_arrays - initializes arrays for Dijkstra's algorithm
* @data: pointer to DijkstraData struct
* @graph: pointer to graph struct
* @start: pointer to starting vertex
*/

void initialize_arrays(DijkstraData *data, graph_t *graph,
						vertex_t const *start)
{
	vertex_t *v;

	data->distance = calloc(graph->nb_vertices, sizeof(*(data->distance)));
	data->from = calloc(graph->nb_vertices, sizeof(*(data->from)));
	data->verts = calloc(graph->nb_vertices, sizeof(*(data->verts)));

	if (!data->distance || !data->from || !data->verts)
	{
		perror("Error initializing arrays");
		cleanup_memory(data);
		exit(EXIT_FAILURE);
	}

	for (v = graph->vertices; v; v = v->next)
		data->verts[v->index] = v, data->distance[v->index] = INT_MAX;

	data->distance[start->index] = 0;
	data->from[start->index] = NULL;
}

/**
* dijkstra_graph - uses Dijkstra's algorithm to find shortest path
* @graph: pointer to graph struct
* @start: pointer to starting vertex
* @target: pointer to target vertex
* Return: queue containing path from start to target, or NULL if no path
*/
queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start,
						vertex_t const *target)
{
	DijkstraData data;
	ssize_t i, d_min, j = -1;
	edge_t *e;
	queue_t *path = queue_create();

	if (!graph || !start || !target || !path)
		return (NULL);

	initialize_arrays(&data, graph, start);

	while (j != (ssize_t)target->index)
	{
		for (d_min = INT_MAX, j = -1, i = 0; i < (ssize_t)graph->nb_vertices; i++)
			if (data.distance[i] >= 0 && data.distance[i] < d_min)
				d_min = data.distance[i], j = i;

		if (j == -1)
			break;

		printf("Checking %s, distance from %s is %d\n",
			data.verts[j]->content, start->content, data.distance[j]);

		for (e = data.verts[j]->edges; e; e = e->next)
			if (data.distance[e->dest->index] >= 0 &&
				data.distance[j] + e->weight < data.distance[e->dest->index])
				data.distance[e->dest->index] = data.distance[j] + e->weight,
				data.from[e->dest->index] = data.verts[j];

		data.distance[j] = -1;
	}

	if (j != -1)
		for (queue_push_front(path, safe_strdup(data.verts[j]->content));
			j != (ssize_t)start->index; j = data.from[j]->index)
			queue_push_front(path, safe_strdup(data.from[j]->content));
	else
		path = (free(path), NULL);

	cleanup_memory(&data);
	return (path);
}
