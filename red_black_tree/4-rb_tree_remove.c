#include "rb_trees.h"





/**
 * rb_tree_fix_delete - Fix Red-Black tree violations after deletion.
 * @tree: Double pointer to the root node of the tree.
 * @node: Node where deletion took place.
 */
void rb_tree_fix_delete(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *sibling;

	while (node != *tree && node->color == BLACK) {
		if (node == node->parent->left) {
			sibling = node->parent->right;
			if (sibling->color == RED) {
				sibling->color = BLACK;
				node->parent->color = RED;
				rotate_left(tree, node->parent);
				sibling = node->parent->right;
			}
			if (sibling->left->color == BLACK && sibling->right->color == BLACK) {
				sibling->color = RED;
				node = node->parent;
			} else {
				if (sibling->right->color == BLACK) {
					sibling->left->color = BLACK;
					sibling->color = RED;
					rotate_right(tree, sibling);
					sibling = node->parent->right;
				}
				sibling->color = node->parent->color;
				node->parent->color = BLACK;
				sibling->right->color = BLACK;
				rotate_left(tree, node->parent);
				node = *tree;
			}
		} else {
			sibling = node->parent->left;
			if (sibling->color == RED) {
				sibling->color = BLACK;
				node->parent->color = RED;
				rotate_right(tree, node->parent);
				sibling = node->parent->left;
			}
			if (sibling->right->color == BLACK && sibling->left->color == BLACK) {
				sibling->color = RED;
				node = node->parent;
			} else {
				if (sibling->left->color == BLACK) {
					sibling->right->color = BLACK;
					sibling->color = RED;
					rotate_left(tree, sibling);
					sibling = node->parent->left;
				}
				sibling->color = node->parent->color;
				node->parent->color = BLACK;
				sibling->left->color = BLACK;
				rotate_right(tree, node->parent);
				node = *tree;
			}
		}
	}
	node->color = BLACK;
}

/**
 * rb_tree_remove - Remove a node from a Red-Black tree.
 * @root: Pointer to the root node of the tree.
 * @n: The value to search and remove.
 * Return: The pointer to the new root of the tree after deletion.
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	if (!root)
		return NULL;


	if (n < root->n)
		root->left = rb_tree_remove(root->left, n);
	else if (n > root->n)
		root->right = rb_tree_remove(root->right, n);
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
			rb_tree_t *temp = rb_tree_min_value_node(root->right);
			root->n = temp->n;
			root->right = rb_tree_remove(root->right, temp->n);
		}
	}

	if (!root)
		return NULL;


	if (root->color == RED || (root->left && root->left->color == RED))
		root->color = BLACK;
	else
		rb_tree_fix_delete(&root, root);

	return root;
}

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


