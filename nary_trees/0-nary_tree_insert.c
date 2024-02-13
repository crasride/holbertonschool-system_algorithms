#include <stdlib.h>
#include <string.h>
#include "nary_trees.h"

/**
* nary_tree_insert - Inserts a node in an N-ary tree.
* @parent: Pointer to the parent node.
* @str: String to be stored in the created node.
*
* Return: Pointer to the created node, or NULL on failure.
*/
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	/* Allocate memory for the new node */
	nary_tree_t *new_node = malloc(sizeof(nary_tree_t));

	if (!str)
		return (NULL);

	if (!new_node)
		return (NULL);

	/* Duplicate the string */
	new_node->content = strdup(str);
	if (!new_node->content)
	{
		free(new_node);
		return (NULL);
	}

	/* Initialize the new node */
	new_node->parent = parent;
	new_node->nb_children = 0;
	new_node->children = NULL;
	new_node->next = NULL;

	/* Add the new node to the beginning of the parent's children linked list */
	if (parent)
	{
		new_node->next = parent->children;
		parent->children = new_node;
	}

	return (new_node);
}
