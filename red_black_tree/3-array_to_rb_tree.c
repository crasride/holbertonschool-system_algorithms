#include "rb_trees.h"

/**
* array_to_rb_tree - Builds a Red-Black Tree from an array.
* @array: Pointer to the first element of the array to be converted.
* @size: The number of elements in the array.
* Return: A pointer to the root node of the created Red-Black tree, or NULL.
*/
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	/* Initializes the root pointer as NULL */
	rb_tree_t *root = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
	{
		rb_tree_insert(&root, array[i]);
	}

	return (root);
}
