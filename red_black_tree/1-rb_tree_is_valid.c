#include "rb_trees.h"

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

int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->color !=BLACK)
		return (0);

	return is_valid_rbt(tree, 0, BLACK);
}

