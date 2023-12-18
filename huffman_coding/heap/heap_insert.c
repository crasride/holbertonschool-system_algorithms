#include "heap.h"

/**
 * initialize_level_order_queue - Initializes the level order queue.
 * @max_size: Maximum size of the queue.
 *
 * Return: Newly initialized queue or NULL on failure.
 */
static binary_tree_node_t **initialize_level_order_queue(int max_size)
{
	int i = 0;
	binary_tree_node_t **level_order_queue = malloc(max_size *
													sizeof(binary_tree_node_t *));

	if (level_order_queue == NULL)
		return (NULL);

	for (i = 0; i < max_size; i++)
		level_order_queue[i] = NULL;

	return (level_order_queue);
}

/**
* level_order_traversal_add - Adds a new node to the binary tree using level
* order traversal.
* @root: Pointer to the root node of the binary tree.
* @new_node: Pointer to the new node to be added.
* @level_order_queue: Pointer to the level order queue.
* @front: Pointer to the front index of the queue.
* @rear: Pointer to the rear index of the queue.
*
* Return: Pointer to the newly added node or NULL on failure.
*/
static binary_tree_node_t *level_order_traversal_add(binary_tree_node_t *root,
binary_tree_node_t *new_node, binary_tree_node_t **level_order_queue,
int *front, int *rear)
{
	level_order_queue[*front] = root;

	/* If the queue is full, double the size of the queue */
	while (level_order_queue[*front])
	{
		if (level_order_queue[*front]->left)
		{
			level_order_queue[*rear] = level_order_queue[*front]->left;
			(*rear)++;
		}
		else /* If left child is NULL, add new node as left child */
		{
			level_order_queue[*front]->left = new_node;
			new_node->parent = level_order_queue[*front];
			return (new_node);
		}

		if (level_order_queue[*front]->right) /* If right child is not NULL */
		{
			level_order_queue[*rear] = level_order_queue[*front]->right;
			(*rear)++;
		}
		else /* If right child is NULL, add new node as right child */
		{
			level_order_queue[*front]->right = new_node;
			new_node->parent = level_order_queue[*front];
			return (new_node);
		}
		(*front)++;
	}

	return (NULL);
}

/**
* add_node - Adds new node to binary tree.
* @root: Pointer to the root node of binary tree.
* @new_node: Pointer to the new node to be added.
*
* Return: Pointer to the newly added node or NULL on failure.
*/
static binary_tree_node_t *add_node(binary_tree_node_t *root,
									binary_tree_node_t *new_node)
{
	binary_tree_node_t *result = NULL;
	/* Initialize the level order queue */
	int front = 0, rear = 1, max_size = 20;
	binary_tree_node_t **level_order_queue =
	initialize_level_order_queue(max_size);

	/* If the queue is NULL, return NULL */
	if (level_order_queue == NULL)
		return (NULL);

	result = level_order_traversal_add(root, new_node, level_order_queue,
										&front, &rear);

	free(level_order_queue);
	return (result);
}


/**
* heap_insert - Inserts a new node into a binary heap.
* @heap: Pointer to the binary heap.
* @data: Pointer to the data to be stored in the new node.
*
* Return: Pointer to the newly inserted node or NULL on failure.
*/
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *new_node = NULL, *current_node;
	void *temp_data;

	if (!heap || !data)
		return (NULL);

	new_node = binary_tree_node(NULL, data);
	if (!heap->root)
	{
		heap->root = new_node;
		heap->size++;
		return (new_node);
	}

	add_node(heap->root, new_node);

	if (new_node)
		heap->size++;

	current_node = new_node;

	/* Swap the new node with its parent while it is smaller than its parent */
	while (current_node->parent && heap->data_cmp(current_node->data,
			current_node->parent->data) < 0)
	{
		temp_data = current_node->data;
		current_node->data = current_node->parent->data;
		current_node->parent->data = temp_data;
		current_node = current_node->parent;
	}

	new_node = current_node;
	return (new_node);
}
