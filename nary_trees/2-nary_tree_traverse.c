#include "nary_trees.h"

/**
* traverse_helper - Helper function for recursive traversal.
* @node: Pointer to the current node.
* @depth: Depth of the current node.
* @action: Pointer to the function to execute for each node.
* @max_depth: Pointer to the maximum depth variable.
*/
static void traverse_helper(nary_tree_t const *node, size_t depth,
	void (*action)(nary_tree_t const *node, size_t depth), size_t *max_depth)
{
	/* Base case */
	nary_tree_t const *child;

	if (node == NULL)
		return;

	/* Execute the action for the current node */
	action(node, depth);

	/* Update max_depth if needed */
	if (depth > *max_depth)
		*max_depth = depth;

	/* Recursively traverse children */
	for (child = node->children; child != NULL; child = child->next)
	{
		traverse_helper(child, depth + 1, action, max_depth);
	}
}

/**
* nary_tree_traverse - Traverse  tree and execute a function for each node.
* @root: Pointer to the root node of the tree.
* @action: Pointer to the function to execute for each node.
*
* Return: The maximum depth of the tree.
*/
size_t nary_tree_traverse(nary_tree_t const *root,
						 void (*action)(nary_tree_t const *node, size_t depth))
{
	/* Initialize the maximum depth */
	size_t max_depth = 0;

	/* Check if the tree or the action is NULL */
	if (root == NULL || action == NULL)
		return (0);

	/* Start the traversal from the root with depth 0 */
	traverse_helper(root, 0, action, &max_depth);

	return (max_depth);
}

