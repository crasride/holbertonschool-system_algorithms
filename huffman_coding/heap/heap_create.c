#include "heap.h"

/**
* heap_create - Creates a Heap data structure
* @data_cmp: Pointer to a comparison function
*
* Return: Pointer to the created heap_t structure, or NULL if it fails
*/
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *new_heap = malloc(sizeof(heap_t));

	if (new_heap == NULL)
		return (NULL);

	new_heap->size = 0;
	new_heap->data_cmp = data_cmp;
	new_heap->root = NULL;

	return (new_heap);
}
