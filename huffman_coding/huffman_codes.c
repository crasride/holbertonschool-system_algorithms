#include "huffman.h"
#include "heap.h"

/**
* huffman_codes_recursive - Recursively traverse the Huffman tree print codes.
*
* @node: Current node being visited.
* @code: Current Huffman code being built.
*/
void huffman_codes_recursive(const binary_tree_node_t *node, char *code)
{
	if (!node)
		return;

	if (!node->left && !node->right)
	{
		printf("%c: %s\n", ((symbol_t *)node->data)->data, code);
		return;
	}

	huffman_codes_recursive(node->left, strcat(strcpy(malloc(strlen(code) + 2),
	code), "0"));


	huffman_codes_recursive(node->right, strcat(strcpy(malloc(strlen(code) + 2),
	code), "1"));

	free(code);
}

/**
* huffman_codes - Builds the Huffman tree and prints resulting Huffman codes.
*
* @data: Array of characters.
* @freq: Array of corresponding frequencies.
* @size: Size of the arrays.
*
* Return: 1 on success, 0 on failure.
*/
int huffman_codes(char *data, size_t *freq, size_t size)
{
	heap_t *priority_queue = NULL;
	binary_tree_node_t *root = NULL;
	char *code = NULL;

	if (!data || !freq || size == 0)
		return (0);

	priority_queue = huffman_priority_queue(data, freq, size);

	if (!priority_queue)
		return (0);

	while (priority_queue->size > 1)
		huffman_extract_and_insert(priority_queue);

	root = heap_extract(priority_queue);

	if (!root)
	{
		heap_delete(priority_queue, free_symbol);
		return (0);
	}

	code = malloc(1);

	if (!code)
	{
		heap_delete(priority_queue, free_symbol);
		free(root);
		return (0);
	}
	code[0] = '\0';

	huffman_codes_recursive(root, code);

	heap_delete(priority_queue, free_symbol);
	free(root);
	return (1);
}