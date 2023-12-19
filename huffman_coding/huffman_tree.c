#include "huffman.h"

/**
* huffman_tree - build a Huffman tree
* @data: array of characters
* @freq: array of associated character frequencies
* @size: size of both arrays
*
* Return: pointer to root node of Huffman tree or NULL on failure
*/
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	heap_t *prio_q;
	binary_tree_node_t *h_tree;

	if (!data || !freq || !size)
		return (NULL);
	prio_q = huffman_priority_queue(data, freq, size);
	if (!prio_q)
		return (NULL);
	while (huffman_extract_and_insert(prio_q))
		;
	h_tree = prio_q->root->data;
	free(prio_q->root);
	free(prio_q);
	return (h_tree);
}
