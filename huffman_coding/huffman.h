#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <stdio.h>
#include <stdlib.h>
#include "heap/heap.h"

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
int huffman_extract_and_insert(heap_t *priority_queue);

/* Functions Task 8*/

/* Functions Task 9*/

#endif /* HUFFMAN_H */
