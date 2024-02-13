#include "nary_trees.h"

/**
* path_exists - Checks if a path exists in an N-ary tree.
* @root: Pointer to the root node of the tree.
* @path: NULL terminated array of strings representing the path.
* Return: 1 if the path exists, 0 otherwise.
*/
int path_exists(nary_tree_t const *root, char const * const *path)
{
	nary_tree_t const *current = root;
	size_t depth = 0;

	while (current && path[depth])
	{
		/* Check if content matches the current node's content */
		if (strcmp(current->content, path[depth]) == 0)
		{
			/* Move to the next depth and reset current to the first child */
			depth++;
			current = current->children;
		}
		else
		{
			/* If content does not match, move to the next sibling */
			current = current->next;
		}
	}
	/*
	*If all elements of the path are present and the last node has no more
	*children
	*/
	return (current == NULL && path[depth] == NULL);
}
