#include "rb_trees.h"

rb_tree_t *rb_tree_remove(rb_tree_t *root, int n)
{
	rb_tree_t *cur = root;

	/* find that guy to kick off */
	while (cur)
	{
		if (cur->n == n)
			break;
		else if (cur->n < n)
			cur = cur->left;
		else
			cur = cur->right;
	}

	if (!cur)
		return (root);
	return (root);
}
