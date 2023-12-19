#include "huffman.h"
#include "../heap/heap.h"

/**
* free_symbol - Frees a symbol_t structure.
* @ptr: Pointer to the symbol_t structure to be freed.
*/
void free_symbol(void *ptr)
{
		if (ptr)
		{
			free(ptr);
		}
}

/**
* symbol_cmp - Compares two symbols based on their frequencies.
* @p1: First symbol pointer.
* @p2: Second symbol pointer.
*
* Return: Difference between the frequencies of the two symbols.
*/
int symbol_cmp(void *p1, void *p2)
{
	/* p1 and p2 are symbol_t* */
	symbol_t *symbol1 = (symbol_t *)p1;
	symbol_t *symbol2 = (symbol_t *)p2;

	return (symbol1->freq - symbol2->freq);
}

/**
* huffman_priority_queue - Creates a priority queue Huffman coding algorithm.
* @data: Array of characters.
* @freq: Array containing associated frequencies.
* @size: Size of the arrays.
*
* Return: Pointer to the created min heap (priority queue).
*/
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *priority_queue;
	binary_tree_node_t *node;
	symbol_t *symbol;
	size_t i;
	/* Check if the data, freq and size are valid */
	if (data == NULL || freq == NULL || size == 0)
		return (NULL);
	/* Create the priority queue */
	priority_queue = heap_create(symbol_cmp);
	if (priority_queue == NULL)
		return (NULL);
	/* Create a node for each symbol and insert it into the heap */
	for (i = 0; i < size; ++i)
	{
		symbol = symbol_create(data[i], freq[i]);
		/* Check if the symbol was created */
		if (symbol == NULL)
		{
			/* If the symbol creation fails, free the priority queue */
			heap_delete(priority_queue, free_symbol);
			return (NULL);
		}
		/* Create a node for the symbol */
		node = binary_tree_node(NULL, symbol);
		/* Check if the node was created */
		if (node == NULL)
		{
			/* If the node creation fails, free the symbol */
			heap_delete(priority_queue, free_symbol);
			return (NULL);
		}
		/* Insert the node into the heap */
		if (heap_insert(priority_queue, node) == NULL)
		{
			/* If the insertion fails, free the symbol and the node */
			heap_delete(priority_queue, free_symbol);
			return (NULL);
		}
	}
	return (priority_queue);
}


