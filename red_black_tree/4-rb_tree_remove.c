#include "rb_trees.h"


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

		if (root->left == NULL || root->right == NULL)
		{
			rb_tree_t *temp = (root->left != NULL) ? root->left : root->right;
			free(root);
			return temp;
		}

		rb_tree_t *temp = find_min(root->right);
		root->right = rb_tree_remove(root->right, temp->n);
	}

	return root;
}
