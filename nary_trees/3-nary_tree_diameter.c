#include "nary_trees.h"

/**
* max - Returns the maximum between two numbers.
* @x: First number.
* @y: Second number.
* Return: The maximum between x and y.
*/
static inline size_t max(size_t x, size_t y)
{
	return (x > y ? x : y);
}

/**
* max_tree_height - Utility function to return the maximum height of the tree.
* @node: Pointer to the current node.
* Return: The maximum depth of the tree.
*/
size_t max_tree_height(nary_tree_t const *node)
{
	size_t max_depth = 0;
	nary_tree_t const *child;

	if (!node)
		return (0);

	for (child = node->children; child; child = child->next)
		max_depth = max(max_depth, max_tree_height(child));

	return (max_depth + 1);
}

/**
* nary_tree_diameter - Computes the diameter of an N-ary tree.
* @root: Pointer to the root node to compute the diameter of.
* Return: The diameter of the tree.
*/
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t first_max_depth = 0, second_max_depth = 0, current_height;
	size_t max_child_diameter = 0;
	nary_tree_t const *current_child;

	if (!root)
		return (0);

	for (current_child = root->children;
			current_child;
			current_child = current_child->next)
	{
		current_height = max_tree_height(current_child);
		if (current_height > first_max_depth)
			second_max_depth = first_max_depth,
			first_max_depth = current_height;
		else if (current_height > second_max_depth)
			second_max_depth = current_height;
	}

	for (current_child = root->children;
				current_child;
				current_child = current_child->next)
		max_child_diameter = max(max_child_diameter,
							nary_tree_diameter(current_child));

	return (max(max_child_diameter, first_max_depth + second_max_depth + 1));
}


