#include "rb_trees.h"

/**
 * rb_tree_remove - Removes a node from a Red-Black tree.
 * @root: Pointer to the root node of the tree.
 * @n: The value to search and remove from the tree.
 * Return: The pointer to the new root of the tree after deletion.
 */
rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	if (root == NULL)
		return root;

	if (n < root->n)
	{
		root->left = rb_tree_remove(root->left, n);
	}
	else if (n > root->n)
	{
		root->right = rb_tree_remove(root->right, n);
	}
	else
	{
		if (root->left == NULL)
		{
			rb_tree_t *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			rb_tree_t *temp = root->left;
			free(root);
			return temp;
		}

		rb_tree_t *temp = find_min(root->right);
		root->n = temp->n;
		root->right = rb_tree_remove(root->right, temp->n);
	}

	return root;
}
