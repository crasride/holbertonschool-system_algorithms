#include "rb_trees.h"

/**
 * rb_rotate_left - Performs a left rotation on a Red-Black Tree
 * @tree: Double pointer to the root node of the Red-Black Tree
 * @node: Pointer to the node to rotate
 */
void rb_rotate_left(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *right = node->right;

	node->right = right->left;

	if (right->left != NULL)
		right->left->parent = node;
	right->parent = node->parent;

	if (node->parent == NULL)
		*tree = right;
	else if (node == node->parent->left)
		node->parent->left = right;
	else
		node->parent->right = right;

	right->left = node;
	node->parent = right;
}

/**
 * rb_rotate_right - Performs a right rotation on a Red-Black Tree
 * @tree: Double pointer to the root node of the Red-Black Tree
 * @node: Pointer to the node to rotate
 */
void rb_rotate_right(rb_tree_t **tree, rb_tree_t *node)
{
	rb_tree_t *left = node->left;

	node->left = left->right;

	if (left->right != NULL)
		left->right->parent = node;

	left->parent = node->parent;

	if (node->parent == NULL)
		*tree = left;
	else if (node == node->parent->right)
		node->parent->right = left;
	else
		node->parent->left = left;

	left->right = node;
	node->parent = left;
}


/**
 * left_sibling - Processing when the corresponding child node is on the right
 * @root: Double pointer to the root node of the Red-Black Tree
 * @child: Pointer to the child node of the deleted node
 * @parent: Pointer to the parent node of the deleted node
 * @sibling: Pointer to the sibling node
 */
void left_sibling(rb_tree_t **root, rb_tree_t **child,
		rb_tree_t **parent, rb_tree_t *sibling)
{
	if (sibling->color == RED)
	{
		sibling->color = BLACK;
		(*parent)->color = RED;
		rb_rotate_left(root, *parent);
		sibling = (*parent)->right;
	}
	if ((sibling->left == NULL || sibling->left->color == BLACK) &&
		(sibling->right == NULL || sibling->right->color == BLACK))
	{
		sibling->color = RED;
		*child = *parent;
		*parent = (*child)->parent;
	}
	else
	{
		if (sibling->right == NULL || sibling->right->color == BLACK)
		{
			sibling->left->color = BLACK;
			sibling->color = RED;
			rb_rotate_right(root, sibling);
			sibling = (*parent)->right;
		}
		sibling->color = (*parent)->color;
		(*parent)->color = BLACK;
		if (sibling->right != NULL)
			sibling->right->color = BLACK;
		rb_rotate_left(root, *parent);
		*child = *root;
		return;
	}
}

/**
 * right_sibling - Processing when the corresponding child node is on the left
 * @root: Double pointer to the root node of the Red-Black Tree
 * @child: Pointer to the child node of the deleted node
 * @parent: Pointer to the parent node of the deleted node
 * @sibling: Pointer to the sibling node
 */
void right_sibling(rb_tree_t **root, rb_tree_t **child,
		rb_tree_t **parent, rb_tree_t *sibling)
{
	if (sibling->color == RED)
	{
		sibling->color = BLACK;
		(*parent)->color = RED;
		rb_rotate_right(root, *parent);
		sibling = (*parent)->left;
	}
	if ((sibling->right == NULL || sibling->right->color == BLACK) &&
		(sibling->left == NULL || sibling->left->color == BLACK))
	{
		sibling->color = RED;
		*child = *parent;
		*parent = (*child)->parent;
	}
	else
	{
		if (sibling->left == NULL || sibling->left->color == BLACK)
		{
			sibling->right->color = BLACK;
			sibling->color = RED;
			rb_rotate_left(root, sibling);
			sibling = (*parent)->left;
		}
		sibling->color = (*parent)->color;
		(*parent)->color = BLACK;
		if (sibling->left != NULL)
			sibling->left->color = BLACK;
		rb_rotate_right(root, *parent);
		*child = *root;
		return;
	}
}

/**
 * rb_tree_delete_fixup - Fixes the Red-Black Tree properties after deletion
 * @root: Double pointer to the root node of the Red-Black Tree
 * @child: Pointer to the child node of the deleted node
 * @parent: Pointer to the parent node of the deleted node
 */
void rb_tree_delete_fixup(rb_tree_t **root, rb_tree_t *child,
		rb_tree_t *parent)
{
	rb_tree_t *sibling;

	while (child != *root && (child == NULL || child->color == BLACK))
	{
		if (child == parent->left)
		{
			sibling = parent->right;
			left_sibling(root, &child, &parent, sibling);
		}
		else
		{
			sibling = parent->left;
			right_sibling(root, &child, &parent, sibling);
		}
	}
	if (child != NULL)
		child->color = BLACK;
}

/**
 * rb_tree_successor - Find the successor node in a Red-Black Tree
 * @node: Pointer to the node
 * Return: Pointer to the successor node, or NULL if not found
 */
rb_tree_t *rb_tree_successor(rb_tree_t *node)
{
	rb_tree_t *successor = node;

	if (successor->right != NULL)
	{
		successor = successor->right;
		while (successor->left != NULL)
			successor = successor->left;
	}
	else
	{
		while (successor->parent != NULL && successor == successor->parent->right)
			successor = successor->parent;
		successor = successor->parent;
	}
	return (successor);
}

/**
 * rb_tree_remove - Removes a node from a Red-Black Tree
 * @root: Pointer to the root node of the tree
 * @n: Value to search and remove from the tree
 * Return: Pointer to the new root of the tree after deletion
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *target, *successor, *child, *parent;

	target = root;
	while (target != NULL && target->n != n)
	{
		if (n < target->n)
			target = target->left;
		else if (n > target->n)
			target = target->right;
	}
	if (target == NULL)
		return (root);
	if (target->left != NULL && target->right != NULL)
	{
		successor = rb_tree_successor(target);
		target->n = successor->n;
		target = successor;
	}
	child = target->left != NULL ? target->left : target->right;
	parent = target->parent;
	if (child != NULL)
		child->parent = parent;
	if (parent == NULL)
		root = child;
	else if (target == parent->left)
		parent->left = child;
	else
		parent->right = child;
	if (target->color == BLACK)
		rb_tree_delete_fixup(&root, child, parent);
	free(target);
	return (root);
}
