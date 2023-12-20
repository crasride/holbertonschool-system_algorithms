#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "heap/heap.h"
#include <string.h>

/**
* struct symbol_s - Stores a char and its associated frequency
*
* @data: The character
* @freq: The associated frequency
*/
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

/* Functions Task 5*/
symbol_t *symbol_create(char data, size_t freq);

/* Functions Task 6*/
void free_symbol(void *ptr);
int symbol_cmp(void *p1, void *p2);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);

/* Functions Task 7*/
int extract_two_nodes(heap_t *priority_queue, binary_tree_node_t **node1,
binary_tree_node_t **node2);

symbol_t *create_combined_symbol(const binary_tree_node_t *node1,
const binary_tree_node_t *node2);

binary_tree_node_t *insert_combined_node(heap_t *priority_queue,
binary_tree_node_t *combined_node);
int huffman_extract_and_insert(heap_t *priority_queue);

/* Functions Task 8*/
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);

/* Functions Task 9*/
int huffman_codes(char *data, size_t *freq, size_t size);

#endif /* HUFFMAN_H */
