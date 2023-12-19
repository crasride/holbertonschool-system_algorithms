#include "heap.h"
#include "huffman.h"

/**
* huffman_extract_and_insert - Extracts two nodes from a priority queue and
* inserts a new one.
* @priority_queue: Pointer to the priority queue.
*
* Return: 1 on success, 0 on failure.
*/
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *node1 = NULL, *node2 = NULL, *new_node = NULL;
	symbol_t *symbol1 = NULL, *symbol2 = NULL, *new_symbol = NULL;

	if (priority_queue == NULL || priority_queue->size < 2)
		return (0);
	/* Extract the two nodes with the lowest frequencies */
	node1 = heap_extract(priority_queue);
	node2 = heap_extract(priority_queue);

	if (node1 == NULL || node2 == NULL)
		return (0);
	/* Convert the void * to symbol_t * before accessing the 'freq' member */
	symbol1 = (symbol_t *)node1->data;
	symbol2 = (symbol_t *)node2->data;
	new_symbol = symbol_create(-1, symbol1->freq + symbol2->freq);

	if (new_symbol == NULL)
	{
		free(node1->data);
		free(node1);
		free(node2->data);
		free(node2);
		return (0);
	}
	/* Create a new node with the new symbol */
	new_node = binary_tree_node(NULL, new_symbol);

	if (new_node == NULL)
	{
		free(node1->data);
		free(node1);
		free(node2->data);
		free(node2);
		free_symbol(new_symbol);
		return (0);
	}
	/* Insert the new node back into the priority queue */
	if (heap_insert(priority_queue, new_node) == NULL)
	{
		free(node1->data);
		free(node1);
		free(node2->data);
		free(node2);
		free_symbol(new_symbol);
		free(new_node);
		return (0);
	}
	return (1);
}
