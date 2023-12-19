#include "heap.h"
#include <stdlib.h>

/**
* free_heap - Recursive function to free the heap nodes.
* @node: Pointer to the current node.
* @free_data: Pointer to the function that frees the data.
*/
static void free_heap(binary_tree_node_t *node, void (*free_data)(void *))
{
	if (node == NULL)
		return;

	free_heap(node->left, free_data);
	free_heap(node->right, free_data);

	if (free_data)
		free_data(node->data);

	free(node);
}

/**
* heap_delete - Deallocates a heap.
* @heap: Pointer to the heap to delete.
* @free_data: Pointer to a function that frees the content of a node.
*/
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (heap == NULL)
		return;

	free_heap(heap->root, free_data);
	free(heap);
}
