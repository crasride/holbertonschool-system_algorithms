#include "rb_trees.h"

/**
* is_valid_rbt - Checks if a subtree is a valid Red-Black Tree.
* @tree: Pointer to the root node of the subtree to check.
* @black_count: Number of black nodes in the path from the root to this node.
* @prev_color: Color of the parent node.
* Return: 1 if it's a valid Red-Black Tree, 0 otherwise.
*/
int is_valid_rbt(const rb_tree_t *tree, int black_count, rb_color_t prev_color)
{
	if (tree == NULL)
		return (1);

	if (prev_color == RED && tree->color == RED)
		return (0);

	if (tree->color == BLACK && prev_color == RED)
		return (0);

	if (tree->color == BLACK)
		black_count++;

	return (is_valid_rbt(tree->left, black_count, tree->color) &&
			is_valid_rbt(tree->right, black_count, tree->color));
}

/**
* rb_tree_is_valid - Checks if a tree is a valid Red-Black Tree.
* @tree: Pointer to the root node of the tree to check.
* Return: 1 if it's a valid Red-Black Tree, 0 otherwise.
*/
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->color != BLACK)
		return (0);

	return (is_valid_rbt(tree, 0, BLACK));
}
