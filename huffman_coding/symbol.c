#include "huffman.h"
#include <stdlib.h>

/**
* symbol_create - Creates a symbol_t data structure.
* @data: The data to be stored in the structure.
* @freq: The associated frequency.
*
* Return: Pointer to the created symbol_t structure, or NULL if it fails.
*/
symbol_t *symbol_create(char data, size_t freq)
{
	/* Allocate memory for the new symbol */
	symbol_t *new_symbol = malloc(sizeof(symbol_t));

	/* Check if malloc failed */
	if (new_symbol == NULL)
		return (NULL);
	/* Initialize the new symbol */
	new_symbol->data = data;
	new_symbol->freq = freq;

	return (new_symbol);
}
