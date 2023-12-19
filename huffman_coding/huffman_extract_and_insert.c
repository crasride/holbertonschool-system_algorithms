#include "heap.h"
#include "huffman.h"

/**
* huffman_extract - Extrae dos nodos del priority_queue.
* @priority_queue: Puntero al priority_queue.
*
* Return: Puntero a nuevo nodo con la suma de las frecuencias o NULL si falla.
*/
binary_tree_node_t *huffman_extract(heap_t *priority_queue)
{
	binary_tree_node_t *node1, *node2;

	if (priority_queue == NULL || priority_queue->size < 2)
		return (NULL);

	/* Extrae los dos nodos con las frecuencias más bajas */
	node1 = heap_extract(priority_queue);
	node2 = heap_extract(priority_queue);

	if (node1 == NULL || node2 == NULL)
		return (NULL);

	/* Crea un nuevo nodo con la suma de las frecuencias */
	return (binary_tree_node(NULL, symbol_create(-1, ((symbol_t *)node1->data)
			->freq + ((symbol_t *)node2->data)->freq)));
}

/**
* huffman_insert - Inserta un nuevo nodo en el priority_queue.
* @priority_queue: Puntero al priority_queue.
* @node: Puntero al nodo que se va a insertar.
*
* Return: 1 en éxito, 0 en fallo.
*/
int huffman_insert(heap_t *priority_queue, binary_tree_node_t *node)
{
	if (priority_queue == NULL || node == NULL)
		return (0);

	/* Inserta el nuevo nodo en el priority_queue */
	return (heap_insert(priority_queue, node) != NULL);
}

/**
* huffman_extract_and_insert - Extrae dos nodos y luego inserta un nuevo nodo.
* @priority_queue: Puntero al priority_queue.
*
* Return: 1 en éxito, 0 en fallo.
*/
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *new_node = huffman_extract(priority_queue);

	if (new_node == NULL)
		return (0);

	/* Inserta el nuevo nodo en el priority_queue */
	return (huffman_insert(priority_queue, new_node));
}
