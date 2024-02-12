<h1 align="center">C - N-ary trees
</h1>

### Resources
**Read or watch:**

* [K-ary trees](https://en.wikipedia.org/wiki/M-ary_tree)
* [N-ary trees in C](https://blog.mozilla.org/nnethercote/2012/03/07/n-ary-trees-in-c/)

### General

## Learning Objectives
* What is a N-ary tree
* What are the most common usage of N-ary trees
* How to represent an N-ary tree in C in at least two different ways
* What is the diameter of an N-ary tree

## Requirements
* Allowed editors: `vi, vim, emacs`
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall -Werror -Wextra and -pedantic`
* All your files should end with a new line
* A `README.md` file, at the root of the folder of the project, is mandatory
* Your code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* You are not allowed to use global variables
* No more than 5 functions per file
* You are allowed to use the standard library
* In the following examples, the `main.c` files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own `main.c` files at compilation. Our `main.c` files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file called `nary_trees.h`
* Don’t forget to push your header file
* All your header files should be include guarded

## More Info

### Data structures
Please use the following data structures and types for this project. Don’t forget to include them in your header file.

```
/**
 * struct nary_tree_s - N-ary tree node structure
 *
 * @content: Content of the node
 * @parent: Pointer to the parent node
 * @nb_children: Number of children
 * @children: Pointer to the head node of the children linked list
 * @next: Pointer to the next child in the parent's children linked list
 */
typedef struct nary_tree_s
{
    char            *content;
    struct nary_tree_s  *parent;
    size_t          nb_children;
    struct nary_tree_s  *children;
    struct nary_tree_s  *next;
} nary_tree_t;
```

### Tasks
### [0. Insert](./0-nary_tree_insert.c)
Write a function that inserts a node in a N-ary tree.

* Prototype: `nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str);`
* Where `parent` is a pointer to the parent node.
* `str` is the string to be stored in the created node. It must be duplicated.
* If `parent` is not NULL, the created node must be added at the beginning of the parent’s children linked list.
* Your function must return a pointer to the created node, or NULL on failure.
```
alex@ubuntu:~/0x04-nary_trees$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 0-nary_tree_insert 0-nary_tree_insert.c 0-main.c
alex@ubuntu:~/0x04-nary_trees$ ./0-nary_tree_insert ; echo $?
0
alex@ubuntu:~/0x04-nary_trees$
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `nary_trees`
* File: `0-nary_tree_insert.c`

---



### [1. Delete](./1-nary_tree_delete.c)
Write a function that deallocates an entire N-ary tree

* `Prototype: void nary_tree_delete(nary_tree_t *tree);`
```
alex@ubuntu:~/0x04-nary_trees$ cat 1-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 1-nary_tree_delete 1-nary_tree_delete.c 0-nary_tree_insert.c 1-main.c
alex@ubuntu:~/0x04-nary_trees$ valgrind ./1-nary_tree_delete
==26867== Memcheck, a memory error detector
==26867== Copyright (C) 2002-2013, and GNU GPL'd, by Julian Seward et al.
==26867== Using Valgrind-3.10.1 and LibVEX; rerun with -h for copyright info
==26867== Command: ./1-nary_tree_delete
==26867==
==26867==
==26867== HEAP SUMMARY:
==26867==     in use at exit: 0 bytes in 0 blocks
==26867==   total heap usage: X allocs, X frees, Y bytes allocated
==26867==
==26867== All heap blocks were freed -- no leaks are possible
==26867==
==26867== For counts of detected and suppressed errors, rerun with: -v
==26867== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
alex@ubuntu:~/0x04-nary_trees$
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `nary_trees`
* File: `1-nary_tree_delete.c`

---

### [2. Traversal](./2-nary_tree_traverse.c)
Write a function that goes through an N-ary tree, node by node.

* Prototype: `size_t nary_tree_traverse(nary_tree_t const *root, void (*action)(nary_tree_t const *node, size_t depth));`
* Where `root` is a pointer to the root node of the tree to traverse
* `action` is a pointer to a function to execute for each node being traversed. Its arguments are:
	* `node` is a pointer to the node being traversed
	* `depth` is the depth of the node being traversed
* Your function must return the biggest depth of the tree pointed to by `root`
```
alex@ubuntu:~/0x04-nary_trees$ cat 2-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

void print_node(nary_tree_t const *node, size_t depth)
{
    printf("%*s%s\n", (int)depth * 2, "", node->content);
}

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    nary_tree_traverse(root, &print_node);

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 2-nary_tree_traverse 2-nary_tree_traverse.c 1-nary_tree_delete.c 0-nary_tree_insert.c 2-main.c
alex@ubuntu:~/0x04-nary_trees$ ./2-nary_tree_traverse
/
  home
    alex
      Applications
      Documents
      Movies
      Pictures
      Downloads
      Desktop
  opt
    Betty
      betty-doc.pl
      betty-style.pl
  var
    www
  tmp
    tmp_file
alex@ubuntu:~/0x04-nary_trees$
```

### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `nary_trees`
* File: `2-nary_tree_traverse.c`

---

### [3. Diameter](./3-nary_tree_diameter.c)
Write a function that computes the diameter of an N-ary tree

* Prototype: `size_t nary_tree_diameter(nary_tree_t const *root);`
* Where `root` is a pointer to the root node of the tree to compute the diameter of.
* Your function must return the diameter of the tree pointed to by `root`.
```
alex@ubuntu:~/0x04-nary_trees$ cat 3-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

void print_node(nary_tree_t const *node, size_t depth)
{
    printf("%*s%s\n", (int)depth * 2, "", node->content);
}

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;
    size_t diameter;

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    diameter = nary_tree_diameter(root);
    printf("Diameter = %lu\n", diameter);

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 3-nary_tree_diameter 3-nary_tree_diameter.c 1-nary_tree_delete.c 0-nary_tree_insert.c 3-main.c
alex@ubuntu:~/0x04-nary_trees$ ./3-nary_tree_diameter
Diameter = 7
alex@ubuntu:~/0x04-nary_trees$
```

### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `nary_trees`
* File: `3-nary_tree_diameter.c`

---

### [4. Path exists](./4-path_exists.c)
Write a function that checks if a path exists in an N-ary tree.

* Prototype: `int path_exists(nary_tree_t const *root, char const * const *path);`
* Where `root` is a pointer to the root node of the tree
* and `path` is a NULL terminated array of strings. The string at the index `i` can be the content of one of the nodes of the tree at the depth  `i.`
* Your function must return `1` if all the elements of `path` are present in the tree and if for an element of `path` at the index `i` is present in one of the nodes at the depth `i.` And of course, all the nodes must be linked to form a path.
```
alex@ubuntu:~/0x04-nary_trees$ cat 4-main.c
#include <stdlib.h>
#include <stdio.h>

#include "nary_trees.h"

void print_node(nary_tree_t const *node, size_t depth)
{
    printf("%*s%s\n", (int)depth * 2, "", node->content);
}

int main(void)
{
    nary_tree_t *root, *tmp, *var, *opt, *betty, *home, *alex;
    char const *path[] = {
        "/",
        "opt",
        "Betty",
        "betty-style.pl",
        NULL
    };
    char const *path2[] = {
        "/",
        "opt",
        "Betty",
        "betty-style.pl",
        "Holberton",
        NULL
    };

    root = nary_tree_insert(NULL, "/");
    if (!root)
    {
        fprintf(stderr, "Failed to create node\n");
        return (EXIT_FAILURE);
    }

    tmp = nary_tree_insert(root, "tmp");
    nary_tree_insert(tmp, "tmp_file");

    var = nary_tree_insert(root, "var");
    nary_tree_insert(var, "www");

    opt = nary_tree_insert(root, "opt");
    betty = nary_tree_insert(opt, "Betty");
    nary_tree_insert(betty, "betty-style.pl");
    nary_tree_insert(betty, "betty-doc.pl");

    home = nary_tree_insert(root, "home");
    alex = nary_tree_insert(home, "alex");
    nary_tree_insert(alex, "Desktop");
    nary_tree_insert(alex, "Downloads");
    nary_tree_insert(alex, "Pictures");
    nary_tree_insert(alex, "Movies");
    nary_tree_insert(alex, "Documents");
    nary_tree_insert(alex, "Applications");

    if (path_exists(root, (char const * const *)path))
        printf("Path exists!\n");
    else
        printf("Path does not exist\n");

    if (path_exists(root, (char const * const *)path2))
        printf("Path2 exists!\n");
    else
        printf("Path2 does not exist\n");

    nary_tree_delete(root);

    return (EXIT_SUCCESS);
}
alex@ubuntu:~/0x04-nary_trees$ gcc -Wall -Wextra -Werror -pedantic -o 4-path_exists 4-path_exists.c 1-nary_tree_delete.c 0-nary_tree_insert.c 4-main.c
alex@ubuntu:~/0x04-nary_trees$ ./4-path_exists
Path exists!
Path2 does not exist
alex@ubuntu:~/0x04-nary_trees$
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `nary_trees`
* File: `4-path_exists.c`
