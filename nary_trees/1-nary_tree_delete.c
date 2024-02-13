#include "nary_trees.h"

/**
* nary_tree_delete - free entire nary_tree_t tree
* @tree: root node of n-ary tree
*/
void nary_tree_delete(nary_tree_t *tree)
{
	/* Temporary variable to traverse the tree */
	nary_tree_t *buffer;

	/* Traverse the tree until the end */
	while (tree)
	{
		/* Save the current node in buffer */
		buffer = tree;
		/* Move to the next node in the linked list of children */
		tree = tree->next;
		/* Recursively delete the children of the current node */
		nary_tree_delete(buffer->children);
		/* Free the content of the current node */
		free(buffer->content);
		/* Free the current node itself */
		free(buffer);
	}
}
