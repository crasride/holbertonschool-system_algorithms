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
	symbol_t *sym1, *sym2;

	sym1 = ((binary_tree_node_t *)p1)->data;
	sym2 = ((binary_tree_node_t *)p2)->data;
	return (sym1->freq - sym2->freq);
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
	heap_t *heap;
	symbol_t *symbol;
	binary_tree_node_t *node;
	size_t i;
	/* Check for NULL */
	if (!data || !freq || size == 0)
		return (NULL);
	/* Create heap */
	heap = heap_create(symbol_cmp);
	if (!heap)
		return (NULL);
	/* Create symbol for each character */
	for (i = 0; i < size; ++i)
	{	/* Create symbol */
		symbol = symbol_create(data[i], freq[i]);
		if (!symbol)
		{
			heap_delete(heap, free_symbol);
			return (NULL);
		}
		/* Create node for symbol */
		node = binary_tree_node(NULL, symbol);
		/* Check for NULL */
		if (!node)
		{
			free_symbol(symbol);
			heap_delete(heap, free_symbol);
			return (NULL);
		}
		/* Insert node into heap */
		if (!heap_insert(heap, node))
		{
			free_symbol(symbol);
			free(node);
			heap_delete(heap, free_symbol);
			return (NULL);
		}
	}
	return (heap);
}
