# C - Red-Black trees

# Resources

### Read or watch:

[Red Black tree](https://en.wikipedia.org/wiki/Red%E2%80%93black_tree)


# General
* What is a Red-Black Tree

## Requirements
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
* The prototypes of all your functions should be included in your header files called `rb_trees.h`
* Don’t forget to push your header files
* All your header files should be include guarded

# More Info

## Data structures
Please use the following data structures and types for this project. Don’t forget to include them in your header file(s). You’ll have to declare the following data structures in your header file `rb_trees.h` in the folder `red_black_tree`.

```
/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 */
typedef enum rb_color_e
{
    RED = 0,
    BLACK,
    DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
    int n;
    rb_color_t color;
    struct rb_tree_s *parent;
    struct rb_tree_s *left;
    struct rb_tree_s *right;
} rb_tree_t;
```

## Print function
To match the examples in the tasks, you are given [`these functions`](https://github.com/hs-hq/0x1E.c)

These functions are used only for visualisation purposes. You don’t have to push them to your repo. They may not be used during the correction

# Task

### [0. Red-Black - New node](./0-rb_tree_node.c)
Write a function that creates a Red-Black Tree node
* Prototype: `rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);`
* Where `parent` is a pointer to the parent node of the node to create
* `value` is the value to put in the new node
* And `color` is the color of the node
* When created, a node does not have any child
* Your function must return a pointer to the new node, or `NULL` on failure
```
alex@/tmp/huffman_rb_trees$ cat 0-main.c
#include <stdlib.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    rb_tree_t *root;

    root = rb_tree_node(NULL, 98, BLACK);

    root->left = rb_tree_node(root, 12, RED);
    root->left->left = rb_tree_node(root->left, 6, BLACK);
    root->left->right = rb_tree_node(root->left, 16, BLACK);

    root->right = rb_tree_node(root, 402, RED);
    root->right->left = rb_tree_node(root->right, 256, BLACK);
    root->right->right = rb_tree_node(root->right, 512, BLACK);

    rb_tree_print(root);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-rb_tree_node.c rb_tree_print.c -o rb_tree_node
alex@/tmp/huffman_rb_trees$ ./rb_tree_node
         .--------B(098)---------.
   .--R(012)---.           .--R(402)---.
B(006)      B(016)      B(256)      B(512)
alex@/tmp/huffman_rb_trees$
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `red_black_tree`
* File: `0-rb_tree_node.c`

### [1. Red-Black - Is Red-Black](./1-rb_tree_is_valid.c)

Write a function that checks if a binary tree is a valid Red-Black Tree
* Prototype: `int rb_tree_is_valid(const rb_tree_t *tree);`
* Where `tree` is a pointer to the root node of the tree to check
* Your function must return `1` if tree is a valid Red-Black Tree, and `0` otherwise
* If `tree` is `NULL`, return `0`

Properties of a Red-Black Tree:
* A Red-Black Tree is a BST
* Every node has a color either red or black.
* Root of tree is always black.
* There are no two adjacent red nodes (A red node cannot have a red parent or red child).
* Every path from root to a NULL node has same number of black nodes.
```
alex@/tmp/huffman_rb_trees$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * valid_rb - Builds a valid R-B tree
 *
 * Return: A pointer to the created tree
 */
rb_tree_t *valid_rb(void)
{
    rb_tree_t *root;

    root = rb_tree_node(NULL, 98, BLACK);
    root->left = rb_tree_node(root, 90, BLACK);
    root->right = rb_tree_node(root, 120, BLACK);
    root->left->left = rb_tree_node(root->left, 79, RED);
    root->left->right = rb_tree_node(root->left, 95, RED);
    return (root);
}

/**
 * not_valid_rb - Builds a not valid R-B tree
 *
 * Return: A pointer to the created tree
 */
rb_tree_t *not_valid_rb(void)
{
    rb_tree_t *root;

    root = rb_tree_node(NULL, 98, BLACK);
    root->left = rb_tree_node(root, 90, RED);
    root->right = rb_tree_node(root, 120, RED);
    root->left->left = rb_tree_node(root->left, 79, BLACK);
    root->left->right = rb_tree_node(root->left, 95, BLACK);
    root->left->right->left = rb_tree_node(root->left->right, 92, RED);
    root->left->right->right = rb_tree_node(root->left->right, 96, RED);
    root->right->right = rb_tree_node(root->right, 130, BLACK);
    return (root);
}

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
    rb_tree_t *root;
    int valid;

    root = valid_rb();
    rb_tree_print(root);
    valid = rb_tree_is_valid(root);
    printf("Is %d valid: %d\n", root->n, valid);

    root = not_valid_rb();
    rb_tree_print(root);
    valid = rb_tree_is_valid(root);
    printf("Is %d valid: %d\n", root->n, valid);

    root->color = RED;
    rb_tree_print(root);
    valid = rb_tree_is_valid(root);
    printf("Is %d valid: %d\n", root->n, valid);
    return (EXIT_SUCCESS);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 1-main.c 1-rb_tree_is_valid.c 0-rb_tree_node.c  rb_tree_print.c -o rb_tree_valid
alex@/tmp/huffman_rb_trees$ ./rb_tree_valid
         .--------B(098)---.
   .--B(090)---.        B(120)
R(079)      R(095)
Is 98 valid: 1
         .--------------------B(098)---.
   .--R(090)---------.              R(120)---.
B(079)         .--B(095)---.              B(130)
            R(092)      R(096)
Is 98 valid: 0
         .--------------------R(098)---.
   .--R(090)---------.              R(120)---.
B(079)         .--B(095)---.              B(130)
            R(092)      R(096)
Is 98 valid: 0
alex@/tmp/huffman_rb_trees$
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `red_black_tree`
* File: `1-rb_tree_is_valid.c`

### [2. Red-Black - Insert](./2-rb_tree_insert.c)
Write a function that inserts a value in a Red-Black Tree
* Prototype: `rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value);`
* Where `tree` is a double pointer to the root node of the Red-Black tree to insert the value in
* And `value` is the value to store in the node to be inserted
* Your function must return a pointer to the created node, or `NULL` on failure
* If the address stored in `tree` is `NULL`, the created node must become the root node.
* If the value is already present in the tree, it must be ignored
* The resulting tree after insertion, must be a Red-Black Tree
* You are allowed to have up to `7` functions in your file
Your file `0-rb_tree_node.c` will be compiled during the compilation
```
alex@/tmp/huffman_rb_trees$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: 0 on success
 */
int main(void)
{
    rb_tree_t *root;
    rb_tree_t *node;

    root = NULL;
    node = rb_tree_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 402);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 512);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 12);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 46);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 256);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 1);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Node should be nil -> %p\n", (void *)node);
    node = rb_tree_insert(&root, 624);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 780);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    return (0);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 2-main.c 0-rb_tree_node.c 2-rb_tree_insert.c rb_tree_print.c -o rb_tree_insert
alex@/tmp/huffman_rb_trees$ ./rb_tree_insert
Inserted: 98
B(098)
Inserted: 402
B(098)---.
      R(402)
Inserted: 512
   .--B(402)---.
R(098)      R(512)
Inserted: 12
         .--B(402)---.
   .--B(098)      B(512)
R(012)
Inserted: 46
         .--------B(402)---.
   .--B(046)---.        B(512)
R(012)      R(098)
Inserted: 128
         .--------------B(402)---.
   .--R(046)---.              B(512)
B(012)      B(098)---.
                  R(128)
Inserted: 256
         .--------------------B(402)---.
   .--R(046)---------.              B(512)
B(012)         .--B(128)---.
            R(098)      R(256)
Inserted: 1
               .--------------------B(402)---.
         .--R(046)---------.              B(512)
   .--B(012)         .--B(128)---.
R(001)            R(098)      R(256)
Node should be nil -> (nil)
Inserted: 624
               .--------------------B(402)---.
         .--R(046)---------.              B(512)---.
   .--B(012)         .--B(128)---.              R(624)
R(001)            R(098)      R(256)
Inserted: 780
               .--------------------B(402)---------.
         .--R(046)---------.                 .--B(624)---.
   .--B(012)         .--B(128)---.        R(512)      R(780)
R(001)            R(098)      R(256)
alex@/tmp/huffman_rb_trees$
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `red_black_tree`
* File: `2-rb_tree_insert.c`

### [3. Red-Black - Array to R-B Tree](./3-array_to_rb_tree.c)
Write a function that builds a Binary Search Tree from an array
* Prototype: `rb_tree_t *array_to_rb_tree(int *array, size_t size);`
* Where `array` is a pointer to the first element of the array to be converted
* And `size` is the number of elements in the array
* Your function must return a pointer to the root node of the created R-B tree, or `NULL` on failure
* If a value in the array is already present in the tree, this value must be ignored
* Your files `2-rb_tree_insert.c` and `0-rb_tree_node.c` will be compiled during the correction
```
alex@/tmp/huffman_rb_trees$ cat 3-main.c
#include <stdlib.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
    rb_tree_t *tree;
    int array[] = {
        79, 47, 68, 87, 84, 91, 21, 32, 34, 2,
        20, 22
    };
    size_t n = sizeof(array) / sizeof(array[0]);

    tree = array_to_rb_tree(array, n);
    if (!tree)
        return (1);
    rb_tree_print(tree);
    return (0);
}
alex@/tmp/huffman_rb_trees$ gcc -Wall -Wextra -Werror -pedantic 3-main.c 0-rb_tree_node.c 2-rb_tree_insert.c 3-array_to_rb_tree.c rb_tree_print.c -o rb_tree_array
alex@/tmp/huffman_rb_trees$ ./rb_tree_array
                           .--------------B(068)---------.
         .--------------B(032)---------.           .--B(084)---.
   .--R(020)---.                 .--B(047)      B(079)      B(087)---.
B(002)      B(021)---.        R(034)                              R(091)
                  R(022)
alex@/tmp/huffman_rb_trees$
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `red_black_tree`
* File: `3-array_to_rb_tree.c`

### [4. Red-Black - Remove](./4-rb_tree_remove.c)
Write a function that removes a node from a Red-Black tree
* Prototype: `rb_tree_t *rb_tree_remove(rb_tree_t *root, int n);`
* Where `root` is a pointer to the root node of the tree
* And `n` is the value to search and remove from the tree
* Your function must return the pointer to the new root of the tree after deletion
* The resulting tree must be a valid Red-Black tree
* You’re allowed to have up to `7` functions in your file
* Your file `0-rb_tree_node.c` will be compiled as well during the correction

### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `red_black_tree`
* File: `4-rb_tree_remove.c, 0-rb_tree_node.c`

### [5. Big O #Red-Black Tree](./5-O)
What are the average time complexities of the below operations for a Red-Black Tree (one answer per line):
* Inserting a node in a Red-Black Tree of size `n`
* Removing a node from a Red-Black Tree of size `n`
* Searching for a node in a Red-Black Tree of size `n`

### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `red_black_tree`
* File: `5-O`
