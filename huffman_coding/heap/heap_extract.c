#include "heap.h"

/**
* pile - Maintains the min-heap property by fixing a potential violation
* at the given node.
* @heap: Pointer to the heap structure.
* @node: Pointer to the node where the heap property may be violated.
*/
void pile(heap_t *heap, binary_tree_node_t *node)
{
	binary_tree_node_t *smallest = node;
	binary_tree_node_t *l_child = node->left;
	binary_tree_node_t *r_child = node->right;

	/* If left child is smaller than root */
	if (r_child != NULL && heap->data_cmp(r_child->data, smallest->data) <= 0)
		smallest = r_child;
	/* If right child is smaller than smallest so far */
	if (l_child != NULL && heap->data_cmp(l_child->data, smallest->data) <= 0)
		smallest = l_child;
	/* If smallest is not root */
	if (smallest != node)
	{
		void *temp = node->data;

		node->data = smallest->data;
		smallest->data = temp;
		/* Recursively pile the affected sub-tree */
		pile(heap, smallest);
	}
}

/**
* get_last_node - Finds the last node in the heap using level order traversal.
* @heap: Pointer to the heap structure.
*
* Return: Pointer to the last node.
*/
binary_tree_node_t *get_last_node(heap_t *heap)
{
	binary_tree_node_t *current;
	binary_tree_node_t *Q[20];
	binary_tree_node_t *last_node;
	int index = 0, count = 0;
	/* Add the root to the queue */
	if (heap->size == 0 || heap->root == NULL)
		return (NULL);
	Q[count++] = heap->root;
	/* Level order traversal to find the last node */
	while (index < count)
	{
		current = Q[index++];

		if (current->left != NULL)
			Q[count++] = current->left;
		if (current->right != NULL)
			Q[count++] = current->right;
	}
	/* Return the last node */
	last_node = Q[count - 1];
	return (last_node);
}

/**
* heap_extract - Extracts the minimum element from the min heap.
* @heap: Pointer to the heap structure.
*
* Return: Pointer to the extracted minimum element.
*/
void *heap_extract(heap_t *heap)
{
	void *min_element = heap->root->data;
	binary_tree_node_t *last_node;
	/* If heap is empty */
	if (heap->size == 0)
		return (NULL);
	/* If heap has only one node */
	if (heap->size == 1)
	{
		free(heap->root);
		heap->root = NULL;
		heap->size = 0;
		return (min_element);
	}
	/* Get the last node */
	last_node = get_last_node(heap);
	/* Replace root with the last node */
	heap->root->data = last_node->data;
	/* Remove last node */
	if (last_node->parent->left == last_node)
		last_node->parent->left = NULL;
	else
		last_node->parent->right = NULL;

	pile(heap, heap->root);
	free(last_node);

	heap->size--;

	return (min_element);
}
