#include "huffman.h"
#include "heap.h"

/**
* huffman_extract_and_insert - Extracts two nodes from a priority queue and
* inserts a new node with a combined frequency.
*
* @priority_queue: Pointer to the heap representing the priority queue.
*
* Return: 1 on success, 0 on failure.
*/
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *node1 = NULL, *node2 = NULL, *node = NULL;
	symbol_t *symbol = NULL;

	if (!priority_queue || priority_queue->size < 2)
		return 0;

	node1 = heap_extract(priority_queue);
	node2 = heap_extract(priority_queue);

	if (!node1 || !node2)
		return 0;

	symbol = symbol_create(-1, ((symbol_t *)node1->data)->freq +
										((symbol_t *)node2->data)->freq);

	if (!symbol)
	{
		free(node1);
		free(node2);
		return 0;
	}

	node = binary_tree_node(NULL, symbol);

	if (!node)
	{
		free_symbol(symbol);
		free(node1);
		free(node2);
		return 0;
	}

	node->left = node1;
	node->right = node2;
	node1->parent = node;
	node2->parent = node;

	if (!heap_insert(priority_queue, node))
	{
		free_symbol(symbol);
		free(node1);
		free(node2);
		free(node);
		return 0;
	}

	return 1;
}
