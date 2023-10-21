#include <stdio.h>
#include <stdlib.h>
#include "rb_trees.h"

/**
 * rb_tree_remove - Removes a node from a Red-Black tree
 * @root: Pointer to the root node of the tree
 * @n: The value to search and remove from the tree
 * Return: Pointer to the new root of the tree after deletion
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	if (!root)
		return NULL;

	root = rb_tree_remove_recursive(root, n);

	if (root)
		root->color = BLACK;

	return root;
}

/**
 * rb_tree_remove_recursive - Helper function for rb_tree_remove
 * @root: Pointer to the root node of the tree
 * @n: The value to search and remove from the tree
 * Return: Pointer to the new root of the tree after deletion
 */
rb_tree_t *rb_tree_remove_recursive(rb_tree_t *root, int n)
{
	if (!root)
		return root;

	if (n < root->n)
		root->left = rb_tree_remove_recursive(root->left, n);
	else if (n > root->n)
		root->right = rb_tree_remove_recursive(root->right, n);
	else {
		if (!root->left || !root->right) {
			rb_tree_t *temp = (root->left) ? root->left : root->right;

			if (!temp) {
				temp = root;
				root = NULL;
			} else
				*root = *temp;
			free(temp);
		} else {
			rb_tree_t *temp = rb_tree_find_min(root->right);

			root->n = temp->n;
			root->right = rb_tree_remove_recursive(root->right, temp->n);
		}
	}

	if (!root)
		return root;

	root = rb_tree_fix_violations(root, n);

	return root;
}

/**
 * rb_tree_find_min - Find the node with the minimum value in a tree
 * @root: Pointer to the root node of the tree
 * Return: Pointer to the node with the minimum value
 */
rb_tree_t *rb_tree_find_min(rb_tree_t *root)
{
	while (root->left)
		root = root->left;
	return root;
}

/**
 * rb_tree_fix_violations - Fix any violations after deleting a node
 * @root: Pointer to the root node of the tree
 * @n: The value that was deleted
 * Return: Pointer to the new root of the tree after fixing violations
 */
rb_tree_t *rb_tree_fix_violations(rb_tree_t *root, int n)
{
	if (root->color == RED || (root->left && root->left->color == RED) || (root->right && root->right->color == RED))
		return root;

	rb_tree_t *parent = NULL, *sibling = NULL, *node = root;
	while (node && !node->color && (node->left || node->right)) {
		parent = node;
		if (n < node->n) {
			if (!node->left || !node->left->color) {
				sibling = node->right;
				if (sibling && sibling->color) {
					sibling->color = 0;
					node->color = 1;
					root = rb_tree_rotate_left(root, node);
					sibling = node->right;
				}
				if ((!sibling->left || !sibling->left->color) && (!sibling->right || !sibling->right->color)) {
					sibling->color = 1;
					node = parent;
				} else {
					if (!sibling->right || !sibling->right->color) {
						sibling->left->color = 0;
						sibling->color = 1;
						root = rb_tree_rotate_right(root, sibling);
						sibling = node->right;
					}
					sibling->color = node->color;
					node->color = 0;
					sibling->right->color = 0;
					root = rb_tree_rotate_left(root, node);
					break;
				}
			}
		} else {
			if (node->left && node->left->color) {
				sibling = node->left;
				if (sibling->color) {
					sibling->color = 0;
					node->color = 1;
					root = rb_tree_rotate_right(root, node);
					sibling = node->left;
				}
				if ((!sibling->left || !sibling->left->color) && (!sibling->right || !sibling->right->color)) {
					sibling->color = 1;
					node = parent;
				} else {
					if (!sibling->left || !sibling->left->color) {
						sibling->right->color = 0;
						sibling->color = 1;
						root = rb_tree_rotate_left(root, sibling);
						sibling = node->left;
					}
					sibling->color = node->color;
					node->color = 0;
					sibling->left->color = 0;
					root = rb_tree_rotate_right(root, node);
					break;
				}
			}
		}
	}
	root->color = 0;
	return root;
}

/**
 * rb_tree_rotate_left - Perform a left rotation on the Red-Black tree
 * @root: Pointer to the root node of the tree
 * @node: The node to rotate around
 * Return: New root after the rotation
 */
rb_tree_t *rb_tree_rotate_left(rb_tree_t *root, rb_tree_t *node)
{
	rb_tree_t *right = node->right;

	node->right = right->left;

	if (right->left)
		right->left->parent = node;

	right->parent = node->parent;

	if (!node->parent)
		root = right;
	else if (node == node->parent->left)
		node->parent->left = right;
	else
		node->parent->right = right;

	right->left = node;
	node->parent = right;

	return root;
}

/**
 * rb_tree_rotate_right - Perform a right rotation on the Red-Black tree
 * @root: Pointer to the root node of the tree
 * @node: The node to rotate around
 * Return: New root after the rotation
 */
rb_tree_t *rb_tree_rotate_right(rb_tree_t *root, rb_tree_t *node)
{
	rb_tree_t *left = node->left;

	node->left = left->right;

	if (left->right)
		left->right->parent = node;

	left->parent = node->parent;

	if (!node->parent)
		root = left;
	else if (node == node->parent->right)
		node->parent->right = left;
	else
		node->parent->left = left;

	left->right = node;
	node->parent = left;

	return root;
}

