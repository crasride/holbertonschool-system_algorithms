#include "nary_trees.h"

/**
* nary_tree_delete - Deallocates an entire N-ary tree.
* @tree: Pointer to the root of the tree to delete.
*/
void nary_tree_delete(nary_tree_t *tree)
{
	if (tree == NULL)
		fprintf(stderr, "Error: NULL tree pointer\n");
	return;

	/* Recursively delete all children */
	while (tree->children)
	{
		nary_tree_delete(tree->children);
	}

	/* Free the content and the node itself */
	if (tree->content != NULL)
		free(tree->content);
	else
		fprintf(stderr, "Warning: NULL content pointer\n");

	/* Update parent's next pointer if needed */
	if (tree->parent != NULL && tree->parent->children == tree)
	{
		tree->parent->children = tree->next;
	}

	free(tree);
}
