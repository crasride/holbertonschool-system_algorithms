#include "rb_trees.h"

/**
 * rotate_left - Perform a left rotation on the given nodes.
 * @tree: Double pointer to the root node of the tree.
 * @parent: Pointer to the parent node to rotate.
 */
void rotate_left(rb_tree_t **tree, rb_tree_t *parent)
{
	rb_tree_t *right_child = parent->right;

	parent->right = right_child->left;

	if (parent->right)
		parent->right->parent = parent;

	right_child->parent = parent->parent;

	if (!parent->parent)
		*tree = right_child;
	else if (parent == parent->parent->left)
		parent->parent->left = right_child;
	else
		parent->parent->right = right_child;

	right_child->left = parent;
	parent->parent = right_child;
}

/**
 * rotate_right - Perform a right rotation on the given nodes.
 * @tree: Double pointer to the root node of the tree.
 * @grandparent: Pointer to the grandparent node to rotate.
 */
void rotate_right(rb_tree_t **tree, rb_tree_t *grandparent)
{
	rb_tree_t *parent = grandparent->left;

	grandparent->left = parent->right;

	if (parent->right)
		parent->right->parent = grandparent;

	parent->parent = grandparent->parent;

	if (!grandparent->parent)
		*tree = parent;
	else if (grandparent == grandparent->parent->left)
		grandparent->parent->left = parent;
	else
		grandparent->parent->right = parent;

	parent->right = grandparent;
	grandparent->parent = parent;
}

/**
 * rb_tree_remove - Removes a node from a Red-Black Tree
 * @root: Pointer to the root node of the tree
 * @n: Value to search and remove from the tree
 * Return: Pointer to the new root of the tree after deletion
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
