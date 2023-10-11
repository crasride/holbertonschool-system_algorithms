#include "rb_trees.h"

/**
 * fix_rb_insert - Fix the Red-Black Tree properties after insertion.
 * @tree: Double pointer to the root node of the tree.
 * @new_node: Pointer to the newly inserted node.
 */
void fix_rb_insert(rb_tree_t **tree, rb_tree_t *new_node)
{
	rb_tree_t *parent = NULL;
	rb_tree_t *grandparent = NULL;
	rb_tree_t *uncle = NULL;

	while (new_node != *tree && new_node->color == RED && new_node->parent->color == RED)
	{
		parent = new_node->parent;
		grandparent = parent->parent;

		/* If parent is the left child of grandparent */
		if (parent == grandparent->left)
		{
			uncle = grandparent->right;

			/* Case 1: Uncle is RED */
			if (uncle && uncle->color == RED)
			{
				grandparent->color = RED;
				parent->color = BLACK;
				uncle->color = BLACK;
				new_node = grandparent;
			}
			else
			{
				/* Case 2: Uncle is BLACK and new_node is the right child */
				if (new_node == parent->right)
				{
					rotate_left(tree, parent);
					new_node = parent;
					parent = new_node->parent;
				}

				/* Case 3: Uncle is BLACK and new_node is the left child */
				rotate_right(tree, grandparent);
				swap_colors(parent, grandparent);
				new_node = parent;
			}
		}
		else /* If parent is the right child of grandparent */
		{
			uncle = grandparent->left;

			/* Case 1: Uncle is RED */
			if (uncle && uncle->color == RED)
			{
				grandparent->color = RED;
				parent->color = BLACK;
				uncle->color = BLACK;
				new_node = grandparent;
			}
			else
			{
				/* Case 2: Uncle is BLACK and new_node is the left child */
				if (new_node == parent->left)
				{
					rotate_right(tree, parent);
					new_node = parent;
					parent = new_node->parent;
				}

				/* Case 3: Uncle is BLACK and new_node is the right child */
				rotate_left(tree, grandparent);
				swap_colors(parent, grandparent);
				new_node = parent;
			}
		}
	}

	(*tree)->color = BLACK;
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
