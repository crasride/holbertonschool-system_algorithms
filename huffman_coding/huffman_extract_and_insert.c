#include "huffman.h"
#include "heap.h"

/**
* extract_two_nodes - Extracts two nodes from a priority queue.
*
* @priority_queue: Pointer to the heap representing the priority queue.
* @node1: Pointer to store the first extracted node.
* @node2: Pointer to store the second extracted node.
*
* Return: 1 on success, 0 on failure.
*/
int extract_two_nodes(heap_t *priority_queue, binary_tree_node_t **node1,
						binary_tree_node_t **node2)
{
	/* Check if the priority queue is valid and has at least two nodes */
	if (!priority_queue || priority_queue->size < 2 || !node1 || !node2)
		return (0);
	/* Extract the two nodes with the lowest frequency */
	*node1 = heap_extract(priority_queue);
	/* Check if the extraction was successful */
	*node2 = heap_extract(priority_queue);

	return (*node1 && *node2);
}

/**
* create_combined_symbol - Creates a new symbol with a combined frequency.
*
* @node1: Pointer to the first node.
* @node2: Pointer to the second node.
*
* Return: Pointer to the created symbol on success, NULL on failure.
*/
symbol_t *create_combined_symbol(const binary_tree_node_t *node1,
									const binary_tree_node_t *node2)
{
	/* Check if the nodes are valid */
	if (!node1 || !node2)
		return (NULL);
	/* Create the new symbol */
	return (symbol_create(-1, ((symbol_t *)node1->data)->freq +
								((symbol_t *)node2->data)->freq));
}

/**
* insert_combined_node - Inserts a new node with combined frequency into the
* priority queue.
*
* @priority_queue: Pointer to the heap representing the priority queue.
* @combined_node: Pointer to the node to be inserted.
*
* Return: Pointer to the inserted node on success, NULL on failure.
*/
binary_tree_node_t *insert_combined_node(heap_t *priority_queue,
											binary_tree_node_t *combined_node)
{
	/* Check if the priority queue and the combined node are valid */
	if (!priority_queue || !combined_node)
		return (NULL);
	/* Insert the combined node into the priority queue */
	if (heap_insert(priority_queue, combined_node))
		return (combined_node);

	return (NULL);
}

/**
 * huffman_extract_and_insert - Extracts two nodes from a priority queue and
 * inserts a new node with a combined frequency.
 *
 * @priority_queue: Pointer to the heap representing the priority queue.
 *
 * Return: 1 on success, 0 on failure.
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	binary_tree_node_t *node1 = NULL, *node2 = NULL, *combined_node = NULL;
	symbol_t *symbol = NULL;

	/* Check if the priority queue is valid and has at least two nodes */
	if (!extract_two_nodes(priority_queue, &node1, &node2))
		return (0);
	/* Create the combined symbol */
	symbol = create_combined_symbol(node1, node2);
	/* Check if the symbol was created successfully */
	if (!symbol)
	{
		free(node1);
		free(node2);
		return (0);
	}
	/* Create the combined node */
	combined_node = binary_tree_node(NULL, symbol);
	/* Check if the combined node was created successfully */
	if (!combined_node)
	{
		free_symbol(symbol);
		free(node1);
		free(node2);
		return (0);
	}
	/* Set the combined node's left and right children */
	combined_node->left = node1;
	combined_node->right = node2;
	node1->parent = combined_node;
	node2->parent = combined_node;
	/* Insert the combined node into the priority queue */
	if (!insert_combined_node(priority_queue, combined_node))
	{
		free_symbol(symbol);
		free(node1);
		free(node2);
		free(combined_node);
		return (0);
	}
	return (1);
}
