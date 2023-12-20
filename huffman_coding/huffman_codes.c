#include "huffman.h"
#include "heap.h"

/**
* huffman_codes_recursive - recursively traverse the huffman tree
* @node: pointer to the current node
* @code: string containing the code
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

	code = strcat(code, "0");
	huffman_codes_recursive(node->left, code);

	code[strlen(code) - 1] = '\0';

	code = strcat(code, "1");
	huffman_codes_recursive(node->right, code);
	code[strlen(code) - 1] = '\0';
}

/**
* huffman_codes - builds the huffman tree and prints the codes
* @data: array of characters
* @freq: array of frequencies of the characters
* @size: size of the array
* Return: 1 on success, 0 on failure
*/
int huffman_codes(char *data, size_t *freq, size_t size)
{
	if (!data || !freq || size == 0)
		return (0);

	heap_t *priority_queue = huffman_priority_queue(data, freq, size);

	if (!priority_queue)
		return (0);

	while (priority_queue->size > 1)
		huffman_extract_and_insert(priority_queue);

	binary_tree_node_t *root = heap_extract(priority_queue);

	if (!root)
	{
		heap_delete(priority_queue, free_symbol);
		return (0);
	}

	char code[256];

	huffman_codes_recursive(root, code);

	heap_delete(priority_queue, free_symbol);
	free(root);
	return (1);
}


