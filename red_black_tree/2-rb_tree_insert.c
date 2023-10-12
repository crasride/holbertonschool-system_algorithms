#include "rb_trees.h"

/**
* fix_rb_insert - tree structure after inserting a new node and ensure that
* Red-Black tree properties are maintained.
*
* @tree: A pointer to the root of the Red-Black tree.
* @new_node: The newly inserted node.
*/
void fix_rb_insert(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *parent = NULL;
	rb_tree_t *grandparent = NULL;
	rb_tree_t *uncle = NULL;

	while (new_node != *tree && new_node->color == RED &&
			new_node->parent->color == RED)
	{
		parent = new_node->parent;
		grandparent = parent->parent;

		if (parent == grandparent->left)
		{
			uncle = grandparent->right;
			handle_case_left(tree, &new_node, parent, grandparent, uncle);
		}
		else
		{
			uncle = grandparent->left;
			handle_case_right(tree, &new_node, parent, grandparent, uncle);
		}
	}

	(*tree)->color = BLACK;
}

/**
* handle_case_left - Handle the case where the newly inserted node is a left
* child in the Red-Black tree.
*
* @tree: A pointer to the root of the Red-Black tree.
* @new_node: A pointer to the newly inserted node.
* @parent: A pointer to the parent of the newly inserted node.
* @grandparent: A pointer to the grandparent of the newly inserted node.
* @uncle: A pointer to the uncle of the newly inserted node.
*/
void handle_case_left(rb_tree_t **tree, rb_tree_t **new_node,
						rb_tree_t *parent, rb_tree_t *grandparent,
						rb_tree_t *uncle)
{
	/* Case 1: Uncle is RED */
	if (uncle && uncle->color == RED)
	{
		grandparent->color = RED;
		parent->color = BLACK;
		uncle->color = BLACK;
		*new_node = grandparent;
	}
	else
	{
		/* Case 2: Uncle is BLACK and new_node is the right child */
		if (*new_node == parent->right)
		{
			rotate_left(tree, parent);
			*new_node = parent;
			parent = (*new_node)->parent;
		}
		/* Case 3: Uncle is BLACK and new_node is the left child */
		rotate_right(tree, grandparent);
		swap_colors(parent, grandparent);
		*new_node = parent;
	}
}

/**
* handle_case_right -the newly inserted node is a right child in the Red-Black
* tree.
*
* @tree: A pointer to the root of the Red-Black tree.
* @new_node: A pointer to the newly inserted node.
* @parent: A pointer to the parent of the newly inserted node.
* @grandparent: A pointer to the grandparent of the newly inserted node.
* @uncle: A pointer to the uncle of the newly inserted node.
*/
void handle_case_right(rb_tree_t **tree, rb_tree_t **new_node,
						rb_tree_t *parent, rb_tree_t *grandparent,
						rb_tree_t *uncle)
{
	/* Case 1: Uncle is RED */
	if (uncle && uncle->color == RED)
	{
		grandparent->color = RED;
		parent->color = BLACK;
		uncle->color = BLACK;
		*new_node = grandparent;
	}
	else
	{
		/* Case 2: Uncle is BLACK and new_node is the left child */
		if (*new_node == parent->left)
		{
			rotate_right(tree, parent);
			*new_node = parent;
			parent = (*new_node)->parent;
		}
		/* Case 3: Uncle is BLACK and new_node is the right child */
		rotate_left(tree, grandparent);
		swap_colors(parent, grandparent);
		*new_node = parent;
	}
}

/**
* rb_tree_insert - Inserts a value in a Red-Black Tree.
* @tree: Double pointer to the root node of the Red-Black tree.
* @value: The value to insert in the tree.
* Return: A pointer to the created node, or NULL on failure.
*/
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *new_node = rb_tree_node(NULL, value, RED);
	rb_tree_t *current = *tree;
	rb_tree_t *parent = NULL;

	if (!new_node)
		return (NULL);

	if (*tree == NULL)
	{
		new_node->color = BLACK;
		*tree = new_node;
		return (new_node);
	}

	while (current != NULL)
	{
		parent = current;
		if (value == current->n)
		{
			free(new_node);
			return (NULL);
		}
		else if (value < current->n)
			current = current->left;
		else
			current = current->right;
	}

	new_node->parent = parent;
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	fix_rb_insert(tree, new_node);

	return (new_node);
}
