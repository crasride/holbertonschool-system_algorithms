<h1 align="center">C - Huffman coding</h1>

## Resources
### Read or watch:

* [Binary Heap](https://en.wikipedia.org/wiki/Binary_heap)
* [Huffman coding](https://en.wikipedia.org/wiki/Huffman_coding)
* [Enumerated Types](https://users.cs.utah.edu/~germain/PPS/Topics/C_Language/enumerated_types.html)
* [Huffman Coding and Huffman Trees](https://www.youtube.com/watch?v=JsTptu56GM8)

## General
* What is a binary Heap (min and max)
* What is a priority queue
* What is a Huffman code

### Requirements
## General
* Allowed editors: `vi`, `vim`, `emacs`
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
* All your files should end with a new line
* A `README.md` file, at the root of the folder of the project, is mandatory
* Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* You are not allowed to use global variables
* No more than 5 functions per file
* You are allowed to use the standard library
* In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header files called `huffman.h` and `heap/heap.h`
* Don’t forget to push your header files
* All your header files should be include guarded


## More Info
### Data structures
Please use the following data structures and types for this project. Don’t forget to include them in your header file(s). You’ll have to declare the following data structures in your header file `heap.h` in the folder `huffman_coding/heap`

```
/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
    void *data;
    struct binary_tree_node_s *left;
    struct binary_tree_node_s *right;
    struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
    size_t size;
    int (*data_cmp)(void *, void *);
    binary_tree_node_t *root;
} heap_t;
```
You’ll have to declare the following data structures in your header file `huffman.h` in the folder `huffman_coding`

```
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
```
Print function

To match the examples in the tasks, you are given [these functions](https://github.com/hs-hq/0x1e.c)

Theses functions are used only for visualisation purpose. You don’t have to push them to your repo. They may not be used during the correction



## Tasks

### [0. Min Binary Heap - Create heap](./heap/heap_create.c)
Write a function that creates a Heap data structure

* Prototype: `heap_t *heap_create(int (*data_cmp)(void *, void *));`
* Where `data_cmp` is a pointer to a comparison function
	* This function takes two `void *` parameters, each one being the data stored in a node.
	* This function will return the difference between the two data stored at those pointers.
	* It will be used to determine if a node’s value is greater or lower than another, so we can build our heap
* Your function must return a pointer to the created `heap_t` structure, or `NULL` if it fails
* `root` must be set to `NULL`
* `size` must be set to `0`
```
alex@/tmp/huffman_coding$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 0-main.c -o heap_create
alex@/tmp/huffman_coding$ ./heap_create
Heap size: 0
Heap root: (nil)
alex@/tmp/huffman_coding$
```
## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `heap/heap_create.c`

### [1. Min Binary Heap - Create node](./heap/binary_tree_node.c)
Write a function that creates a generic Binary Tree node
* Prototype: `binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);`
* Where `parent` is a pointer to the parent node of the node to be created
* And `data` is the data to be stored in the node
* Your function must return a pointer to the created node or `NULL` if it fails
```
alex@/tmp/huffman_coding$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    binary_tree_node_t *node;
    int n, n2;

    n = 5;
    n2 = 10;
    node = binary_tree_node(NULL, &n);
    if (node == NULL)
    {
        fprintf(stderr, "Failed to create a node\n");
        return (EXIT_FAILURE);
    }
    printf("Node(%p): data(%d) left(%p) right(%p) parent(%p)\n",
        (void *)node, *((int *)node->data), (void *)node->left,
        (void *)node->right, (void *)node->parent);

    node->left = binary_tree_node(node, &n2);
    if (node == NULL)
    {
        fprintf(stderr, "Failed to create a node\n");
        return (EXIT_FAILURE);
    }
    printf("Node(%p): data(%d) left(%p) right(%p) parent(%p)\n",
        (void *)node->left, *((int *)node->left->data), (void *)node->left->left,
        (void *)node->left->right, (void *)node->left->parent);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 1-main.c -o binary_tree_node
alex@/tmp/huffman_coding$ ./binary_tree_node
Node(0x17e9010): data(5) left((nil)) right((nil)) parent((nil))
Node(0x17e9040): data(10) left((nil)) right((nil)) parent(0x17e9010)
alex@/tmp/huffman_coding$
```
## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `heap/binary_tree_node.c`

### [2. Min Binary Heap - Insert node](./heap/heap_insert.c)
Write a function that inserts a value in a Min Binary Heap
* Prototype: `binary_tree_node_t *heap_insert(heap_t *heap, void *data);`
* Where `heap` is a pointer to the heap in which the node has to be inserted
* And `data` is a pointer containing the data to store in the new node
* Your function must return a pointer to the created node containing `data`, or `NULL` if it fails
* The `size` of `heap` must be incremented if the function succeed
* If `heap` is `NULL`, your function should fail
* If `data` is `NULL`, your function should not fail
* If `heap->root` is `NULL,` then the new node must take its place
* You are allowed to have at most 7 functions in your file
```
alex@/tmp/huffman_coding$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * print_int - Stores a string in a buffer
 *
 * @buffer: Buffer to store the string
 * @data: Pointer to the string
 *
 * Return: Number of bytes written in buffer
 */
int print_int(char *buffer, void *data)
{
    int *n;
    int length;

    n = (int *)data;
    length = sprintf(buffer, "(%03d)", *n);
    return (length);
}

void binary_tree_print(const binary_tree_node_t *root, int (*print_data)(char *, void *));

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;
    int array[] = {
        34, 2, 45, 23, 76
    };
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;
    binary_tree_node_t *node;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);

    for (i = 0; i < size; ++i)
    {
        node = heap_insert(heap, &(array[i]));
        if (node == NULL)
        {
            fprintf(stderr, "Failed to insert a node\n");
            return (EXIT_FAILURE);
        }
        binary_tree_print(heap->root, print_int);
        printf("\n");
    }
    printf("Heap size: %lu\n", heap->size);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 2-main.c binary_tree_print.c -o heap_insert
alex@/tmp/huffman_coding$ ./heap_insert
Heap size: 0
Heap root: (nil)
(034)

  .--(002)
(034)

  .--(002)--.
(034)     (045)

       .--(002)--.
  .--(023)     (045)
(034)

       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)

Heap size: 5
alex@/tmp/huffman_coding$
```
## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `heap/heap_insert.c, heap/binary_tree_node.c, heap/heap_create.c`

### [3. Min Binary Heap - Extract](./heap/heap_extract.c)
Write a function that extracts the root value of a Min Binary Heap
* Prototype: `void *heap_extract(heap_t *heap);`
* Where `heap` is a pointer to the heap from which to extract the value
* Your function must return a pointer to the data that was stored in the root node of the heap
* Once the data is extracted, the root node must be freed, and replaced by the last node of the heap. Then the heap must be rebuild if necessary
* If your function fails, or `heap` is `NULL`, it must return `NULL`
* You are allowed to have at most 7 functions in your file
```
alex@/tmp/huffman_coding$ cat 3-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * print_int - Stores a string in a buffer
 *
 * @buffer: Buffer to store the string
 * @data: Pointer to the string
 *
 * Return: Number of bytes written in buffer
 */
int print_int(char *buffer, void *data)
{
    int *n;
    int length;

    n = (int *)data;
    length = sprintf(buffer, "(%03d)", *n);
    return (length);
}

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;
    int array[] = {
        34, 2, 45, 23, 76
    };
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;
    binary_tree_node_t *node;
    int *extracted;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);

    for (i = 0; i < size; ++i)
    {
        node = heap_insert(heap, &(array[i]));
        if (node == NULL)
        {
            fprintf(stderr, "Failed to insert a node\n");
            return (EXIT_FAILURE);
        }
    }
    binary_tree_print(heap->root, print_int);
    printf("Heap size: %lu\n\n", heap->size);

    extracted = (int *)heap_extract(heap);
    printf("Extracted: %d\n", *extracted);
    binary_tree_print(heap->root, print_int);
    printf("Heap size: %lu\n", heap->size);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 3-main.c binary_tree_print.c -o heap_extract
alex@/tmp/huffman_coding$ ./heap_extract
Heap size: 0
Heap root: (nil)
       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)
Heap size: 5

Extracted: 2
       .--(023)--.
  .--(034)     (045)
(076)
Heap size: 4
alex@/tmp/huffman_coding$
```
## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `heap/heap_extract.c`

### [4. Min Binary Heap - Delete heap](./heap/heap_delete.c)
Write a function that deallocates a heap
* Prototype: `void heap_delete(heap_t *heap, void (*free_data)(void *));`
* Where `heap` is a pointer to the heap to delete
* And `free_data` is a pointer to a function that will be used to free the content of a node
* Your function must free the entire tree starting at `heap->root` and the heap structure itself
* If `free_data` is `NULL,` the data stored in the nodes must not be freed
```
alex@/tmp/huffman_coding$ cat 4-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"

/**
 * int_cmp - Compares two integers
 *
 * @p1: First pointer
 * @p2: Second pointer
 *
 * Return: Difference between the two strings
 */
int int_cmp(void *p1, void *p2)
{
    int *n1, *n2;

    n1 = (int *)p1;
    n2 = (int *)p2;
    return (*n1 - *n2);
}

/**
 * print_int - Stores a string in a buffer
 *
 * @buffer: Buffer to store the string
 * @data: Pointer to the string
 *
 * Return: Number of bytes written in buffer
 */
int print_int(char *buffer, void *data)
{
    int *n;
    int length;

    n = (int *)data;
    length = sprintf(buffer, "(%03d)", *n);
    return (length);
}

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    heap_t *heap;
    int array[] = {
        34, 2, 45, 23, 76
    };
    size_t size = sizeof(array) / sizeof(array[0]);
    size_t i;
    binary_tree_node_t *node;

    heap = heap_create(int_cmp);
    if (heap == NULL)
    {
        fprintf(stderr, "Failed to create the heap\n");
        return (EXIT_FAILURE);
    }
    printf("Heap size: %lu\n", heap->size);
    printf("Heap root: %p\n", (void *)heap->root);

    for (i = 0; i < size; ++i)
    {
        node = heap_insert(heap, &(array[i]));
        if (node == NULL)
        {
            fprintf(stderr, "Failed to insert a node\n");
            return (EXIT_FAILURE);
        }
        binary_tree_print(heap->root, print_int);
        printf("\n");
    }
    printf("Heap size: %lu\n", heap->size);
    heap_delete(heap, NULL);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 4-main.c binary_tree_print.c -o heap_delete
alex@/tmp/huffman_coding$ valgrind ./heap_delete
==102349== Memcheck, a memory error detector
==102349== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==102349== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==102349== Command: ./heap_delete
==102349==
Heap size: 0
Heap root: (nil)
(034)

  .--(002)
(034)

  .--(002)--.
(034)     (045)

       .--(002)--.
  .--(023)     (045)
(034)

       .-------(002)--.
  .--(023)--.       (045)
(034)     (076)

Heap size: 5
==102349==
==102349== HEAP SUMMARY:
==102349==     in use at exit: 0 bytes in 0 blocks
==102349==   total heap usage: 36 allocs, 36 frees, 3,373 bytes allocated
==102349==
==102349== All heap blocks were freed -- no leaks are possible
==102349==
==102349== For counts of detected and suppressed errors, rerun with: -v
==102349== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/huffman_coding$
```
## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `heap/heap_delete.c`

### [5. Symbols: Create symbol](./symbol.c)
Write a function that creates a `symbol_t` data structure
* Prototype: `symbol_t *symbol_create(char data, size_t freq);`
* Where `data` is the data to be stored in the structure
* And `freq` is its associated frequency
* Your function must return a pointer to the created structure, or `NULL` if it fails
```
alex@/tmp/huffman_coding$ cat 5-main.c
#include <stdlib.h>
#include <stdio.h>
#include "huffman.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS
 */
int main(void)
{
    symbol_t *symbol;

    symbol = symbol_create('d', 3);
    if (symbol == NULL)
    {
        fprintf(stderr, "Failed to create a symbol\n");
        return (EXIT_FAILURE);
    }
    printf("Symbol: data(%c) frequency(%lu)\n", symbol->data, symbol->freq);

    symbol = symbol_create('H', 98);
    if (symbol == NULL)
    {
        fprintf(stderr, "Failed to create a symbol\n");
        return (EXIT_FAILURE);
    }
    printf("Symbol: data(%c) frequency(%lu)\n", symbol->data, symbol->freq);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 5-main.c symbol.c -o symbol_create
alex@/tmp/huffman_coding$ ./symbol_create
Symbol: data(d) frequency(3)
Symbol: data(H) frequency(98)
alex@/tmp/huffman_coding$
```

## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `symbol.c`


### [6. Huffman coding - Step 1: Priority queue](./huffman_priority_queue.c)
The first step to get the Huffman codes of our letters is to build a priority queue. The value of frequency field will be used to compare two nodes in this min heap. Once built, the least frequent character will be stored in the root node of our priority queue.

Write a function that creates a priority queue for the Huffman coding algorithm

* Prototype: `heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);`
* Where `data` is an array of characters of size `size`
* And `freq` is an array containing the associated frequencies (of size `size` too)
* Your function must return a pointer to the created min heap (also called priority queue)
* Each node of this priority queue stores a heap leaf node containing a `symbol_t *`
	* `node->data` is a `binary_tree_node_t *` (let’s call it `nested`)
	* `nested->data` is our `symbol_t *`
```
alex@/tmp/huffman_coding$ cat 6-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * nested_print - Prints a symbol structure stored in a nested node
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int nested_print(char *buffer, void *data)
{
    binary_tree_node_t *nested;
    symbol_t *symbol;
    int length;

    nested = (binary_tree_node_t *)data;
    symbol = (symbol_t *)nested->data;
    length = sprintf(buffer, "(%c/%lu)", symbol->data, symbol->freq);
    return (length);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    heap_t *priority_queue;
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);

    priority_queue = huffman_priority_queue(data, freq, size);
    if (!priority_queue)
    {
        fprintf(stderr, "Failed to create priority queue\n");
        return (EXIT_FAILURE);
    }
    binary_tree_print(priority_queue->root, nested_print);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 6-main.c symbol.c huffman_priority_queue.c binary_tree_print.c -o prio
alex@/tmp/huffman_coding$ ./prio
         .--------(a/6)---------.
   .--(b/11)---.          .--(c/12)
(d/13)      (e/16)     (f/36)
alex@/tmp/huffman_coding$
```
## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `huffman_priority_queue.c`

### [7. Huffman coding - Step 2: Extract ](./huffman_extract_and_insert.c)
Once we have our priority queue initialized, the next step is to build the Huffman tree. First we need to understand the process of building such a tree. We need to extract the two least frequent symbols from our priority queue, add their frequencies, and store this new frequency back in our priority queue.

Remember that in our priority queue, each node stores a leaf node that stores our `symbol_t *`. The goal here, is to make the two extracted nodes(containing the `symbol_t *`) the children of the new node we will create (the one that will store the the sum of the two frequencies). The first extracted node will be the left child, and the second one will be the right child. Then this node will be stored (inside a node) in our priority queue.

So, at the end of this process, our priority queue will see its size decreased by one (we extract two, we insert back one). Note that we will use the value `-1` as the `char data` for the new `symbol` we will create. (In the example below, we print it as a dollar sign)

Write a function that extracts the two nodes of the priority queue and insert a new one
* Prototype: `int huffman_extract_and_insert(heap_t *priority_queue);`
* Where `priority_queue` is a pointer to the priority queue to extract from
* Your function must return `1` on success or `0` on failure
```
alex@/tmp/huffman_coding$ cat 7-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * nested_print - Prints a symbol structure stored in a nested node
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int nested_print(char *buffer, void *data)
{
    binary_tree_node_t *nested;
    symbol_t *symbol;
    char c;
    int length;

    nested = (binary_tree_node_t *)data;
    symbol = (symbol_t *)nested->data;
    c = symbol->data;
    if (c == -1)
        c = '$';
    length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
    return (length);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    heap_t *priority_queue;
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);

    priority_queue = huffman_priority_queue(data, freq, size);
    if (!priority_queue)
    {
        fprintf(stderr, "Failed to create priority queue\n");
        return (EXIT_FAILURE);
    }
    binary_tree_print(priority_queue->root, nested_print);
    printf("\n");

    huffman_extract_and_insert(priority_queue);
    binary_tree_print(priority_queue->root, nested_print);
    printf("\n");

    huffman_extract_and_insert(priority_queue);
    binary_tree_print(priority_queue->root, nested_print);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 7-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c binary_tree_print.c -o extract
alex@/tmp/huffman_coding$ ./extract
         .--------(a/6)---------.
   .--(b/11)---.          .--(c/12)
(d/13)      (e/16)     (f/36)

         .--------(c/12)---.
   .--(d/13)---.        (e/16)
(f/36)      ($/17)

         .--(e/16)---.
   .--($/17)      (f/36)
($/25)
alex@/tmp/huffman_coding$
```
In the above example, you can see after the first call to `huffman_extract_and_insert` that the nodes `a/6` and `b/11` have been extracted and that a new node `$/17` has been inserted. (`$` meaning `-1`, and `17` being `6 + 11`)

## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `huffman_extract_and_insert.c`


### [8. Huffman coding - Step 3: Build Huffman tree](./huffman_tree.c)
Following the previous step, we now have to iterate the same operation until there is only one node remaining in our priority queue. This final node will store the root node of our Huffman tree.

Write a function that builds the Huffman tree

* Prototype: `binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);`
* Where `data` is an array of characters of size `size`
* And `freq` is an array containing the associated frequencies (of size  `size` too)
* Your function must return a pointer to the root node of the Huffman tree, or `NULL` if it fails
* Remember that you have to return the root node of the Huffman tree, not the root node of the priority queue. Each node of the priority queue stores a node.
```
alex@/tmp/huffman_coding$ cat 8-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));

/**
 * symbol_print - Prints a symbol structure
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int symbol_print(char *buffer, void *data)
{
    symbol_t *symbol;
    char c;
    int length;

    symbol = (symbol_t *)data;
    c = symbol->data;
    if (c == -1)
        c = '$';
    length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
    return (length);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    binary_tree_node_t *root;
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);

    root = huffman_tree(data, freq, size);
    if (!root)
    {
        fprintf(stderr, "Failed to build Huffman tree\n");
        return (EXIT_FAILURE);
    }
    binary_tree_print(root, symbol_print);

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 8-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c binary_tree_print.c -o huffman_tree
alex@/tmp/huffman_coding$ ./huffman_tree
   .--($/94)---------------------.
(f/36)               .--------($/58)---------.
               .--($/25)---.           .--($/33)--------.
            (c/12)      (d/13)      (e/16)        .--($/17)---.
                                                (a/6)      (b/11)
alex@/tmp/huffman_coding$
```
## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `huffman_tree.c`


### [9. Huffman coding - Step 4: Huffman codes](./huffman_codes.c)
Now that we have our Huffman tree, we are able to get the Huffman codes for each letter. This process is pretty straight forward: go through the Huffman tree starting at the root node. Each time you go to the left node, append a `0` to the code. Each time you go to the right, append a 0 to the code. When you hit a leaf node, get the letter and print its corresponding Huffman code.

Write a function that build the Huffman tree and print the resulting Huffman codes for each symbol
* Prototype: `int huffman_codes(char *data, size_t *freq, size_t size);`
* Where `data` is an array of characters of size size
* And `freq` is an array containing the associated frequencies (of size size too)
* Your function must return `1` if it succeed, `0` if it fails
```
alex@/tmp/huffman_coding$ cat 9-main.c
#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);

    if (!huffman_codes(data, freq, size))
    {
        fprintf(stderr, "Failed to get Huffman codes\n");
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_coding$ gcc -Wall -Wextra -Werror -pedantic -Iheap/ -I./ heap/*.c 9-main.c symbol.c huffman_priority_queue.c huffman_extract_and_insert.c huffman_tree.c huffman_codes.c binary_tree_print.c -o huffman_codes
alex@/tmp/huffman_coding$ valgrind ./huffman_codes
==102860== Memcheck, a memory error detector
==102860== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==102860== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==102860== Command: ./huffman_codes
==102860==
f: 0
c: 100
d: 101
e: 110
a: 1110
b: 1111
==102860==
==102860== HEAP SUMMARY:
==102860==     in use at exit: 0 bytes in 0 blocks
==102860==   total heap usage: 111 allocs, 111 frees, 2,592 bytes allocated
==102860==
==102860== All heap blocks were freed -- no leaks are possible
==102860==
==102860== For counts of detected and suppressed errors, rerun with: -v
==102860== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@/tmp/huffman_coding$
```
## Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `huffman_coding`
* File: `huffman_codes.c`
