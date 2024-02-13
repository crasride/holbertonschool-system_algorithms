#include "nary_trees.h"

/**
* path_exists - Checks if a path exists in an N-ary tree.
* @root: Pointer to the root node of the tree.
* @path: NULL-terminated array of strings representing the path.
*
* Return: 1 if the path exists, 0 otherwise.
*/
int path_exists(nary_tree_t const *root, char const * const *path)
{
	size_t path_index;

	/* Check for invalid input parameters */
	if (!root || !path || !*path)
		return (0);

	/* Iterate through each element of the path */
	for (path_index = 0; path[path_index]; ++path_index, root = root->children)
	{
		/* Search for the current element in the current level of the tree */
		while (root && strcmp(root->content, path[path_index]) != 0)
			root = root->next;

		/* Current element is not found at the current level, path does not exist */
		if (!root)
			return (0);
	}

	/* All elements of the path are found in the tree, and they form a path */
	return (1);
}


