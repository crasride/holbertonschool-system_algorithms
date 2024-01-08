<h1 align="center">C - Pathfinding</h1>

<p align="center">
	<img width="" height="250" src="../images/Pathfinding.gif" alt="menger">
</p>

## Resources
### Read or watch:

* [Pathfinding](https://en.wikipedia.org/wiki/Pathfinding)
* [Backtracking](https://en.wikipedia.org/wiki/Backtracking)
* [Dijkstra’s Algorithm](https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm)
* [Dijkstra’s Algorithm - Computerphile](https://www.youtube.com/watch?v=GazC3A4OQTE)
* [A Star algorithm](https://en.wikipedia.org/wiki/A*_search_algorithm)
* [A Star Search Algorithm - Computerphile](https://www.youtube.com/watch?v=ySN5Wnu88nE)
* [Brief description of the algorithms described above](./note.md)

## Learning Objectives
At the end of this project, you are expected to be able to explain to anyone, without the help of Google:

### General
* What is pathfinding
* What are the most common applications of pathfinding
* What is backtracking, and why you should never use it
* What is Dijkstra’s algorithm, and what is its main weakness
* What is A star algorithm, and how it is better than Dijkstra’s


## Requirements

### General
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic
* All your files should end with a new line
* A README.md file, at the root of the folder of the project, is mandatory
* Your code should use the Betty style. It will be checked using [betty-style.pl](https://github.com/holbertonschool/Betty/blob/master/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/blob/master/betty-doc.pl)
* You are not allowed to use global variables
* No more than 5 functions per file
* You are allowed to use the standard library
* In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don’t have to push them to your repo (if you do we won’t take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
* The prototypes of all your functions should be included in your header file called pathfinding.h
* Don’t forget to push your header file
* All your header files should be include guarded

## More Info
### Data Structures
Please use the following data structures and types for binary trees. Don’t forget to include them in your header file pathfinding.h.

```
/**
 * struct point_s - Structure storing coordinates
 *
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
    int x;
    int y;
} point_t;
```
### Libraries
For this project, you are given two libraries, containing utility functions to manipulate `graphs` and `queues`. [You can find these libraries here](https://github.com/hs-hq/0x07-pathfinding.c).

This repository will be used during the auto-review, thus your code will be compiled using `-lgraphs` and `-lqueues`.

# Tasks

### [0. Backtracking - Array](./0-backtracking_array.c)
Write a function that searches for the first path from a starting point to a target point within a two-dimensional array.

* Prototype: `queue_t *backtracking_array(char **map, int rows, int cols, point_t const *start, point_t const *target);`
* Where:
	* map is the pointer to a read-only two-dimensional array
		* A `0` represents a walkable cell
		* A `1` represents a blocked cell
	* `rows` and `cols` are respectively the number of rows and columns of `map`
	* `start` stores the coordinates of the starting point
	* `target` stores the coordinates of the target point
* Your function must return a queue, in which each node is a point in the path from `start` to `target` (See example)
* You’ll have to use recursive backtracking to find the first working path from `start` to `target`
* For each visited cell, you’ll have to explore neighbour cells in the following order:
	* `RIGHT`
	* `BOTTOM`
	* `LEFT`
	* `TOP`
* You’ll have to print each visited cell as in the example below

```
alex@~/pathfinding$ cat 0-main.c
#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
    printf("Path found:\n");
    while (path->front)
    {
        point_t *point = (point_t *)dequeue(path);
        printf(" [%d, %d]\n", point->x, point->y);
        free(point);
    }
    free(path);
}

/**
 * main - Backtracking using an array. Here the array is chosen to demonstrate
 * that Backtracking is a really bad algorithm. The target point is just
 * down-right from the starting point, but since we first check the right cell,
 * then top, then left, then bottom, our algo will almost go through the whole
 * maze before finding a path.
 * Don't use backtracking. Backtracking is bad.
 */
int main(void)
{
    char *map[21] = {
        "111111111111111111111",
        "101000000000001000001",
        "101011111111101110101",
        "100010000010001000101",
        "111111111010111011101",
        "101000000010100010001",
        "101011111010111011111",
        "101000001010001000001",
        "101110111011101111101",
        "101000001000100000101",
        "101011111110111110101",
        "101000000010000010001",
        "101111101111101111101",
        "000000001000001000001",
        "111011111010101011111",
        "100010100010101000001",
        "101110101111111110111",
        "100000101000000000001",
        "101111101011111111101",
        "100000100000000010001",
        "111110111111111111111"
    };
    point_t start = { 0, 13 };
    point_t target = { 5, 20 };
    queue_t *path;

    path = backtracking_array((char **)map, 21, 21, &start, &target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);

    return (EXIT_SUCCESS);
}
alex@~/pathfinding$ gcc -o 0-backtracking_array -Wall -Wextra -Werror -pedantic 0-main.c 0-backtracking_array.c -lqueues
alex@~/pathfinding$ ./0-backtracking_array 
Checking coordinates [0, 13]
Checking coordinates [1, 13]
Checking coordinates [2, 13]
Checking coordinates [3, 13]
Checking coordinates [4, 13]
Checking coordinates [5, 13]
Checking coordinates [6, 13]
Checking coordinates [7, 13]
Checking coordinates [7, 12]
Checking coordinates [7, 11]
Checking coordinates [8, 11]
Checking coordinates [9, 11]
Checking coordinates [6, 11]
Checking coordinates [5, 11]
Checking coordinates [4, 11]
Checking coordinates [3, 11]
Checking coordinates [3, 10]
Checking coordinates [3, 9]
Checking coordinates [4, 9]
Checking coordinates [5, 9]
Checking coordinates [6, 9]
Checking coordinates [7, 9]
Checking coordinates [5, 8]
Checking coordinates [5, 7]
Checking coordinates [6, 7]
Checking coordinates [7, 7]
Checking coordinates [4, 7]
Checking coordinates [3, 7]
Checking coordinates [3, 6]
Checking coordinates [3, 5]
Checking coordinates [4, 5]
Checking coordinates [5, 5]
Checking coordinates [6, 5]
Checking coordinates [7, 5]
Checking coordinates [8, 5]
Checking coordinates [9, 5]
Checking coordinates [9, 6]
Checking coordinates [9, 7]
Checking coordinates [9, 8]
Checking coordinates [9, 9]
Checking coordinates [10, 9]
Checking coordinates [11, 9]
Checking coordinates [11, 10]
Checking coordinates [11, 11]
Checking coordinates [12, 11]
Checking coordinates [13, 11]
Checking coordinates [14, 11]
Checking coordinates [15, 11]
Checking coordinates [13, 12]
Checking coordinates [13, 13]
Checking coordinates [13, 14]
Checking coordinates [13, 15]
Checking coordinates [12, 13]
Checking coordinates [11, 13]
Checking coordinates [11, 14]
Checking coordinates [11, 15]
Checking coordinates [10, 13]
Checking coordinates [9, 13]
Checking coordinates [9, 14]
Checking coordinates [9, 15]
Checking coordinates [8, 15]
Checking coordinates [7, 15]
Checking coordinates [7, 16]
Checking coordinates [7, 17]
Checking coordinates [7, 18]
Checking coordinates [7, 19]
Checking coordinates [8, 19]
Checking coordinates [9, 19]
Checking coordinates [10, 19]
Checking coordinates [11, 19]
Checking coordinates [12, 19]
Checking coordinates [13, 19]
Checking coordinates [14, 19]
Checking coordinates [15, 19]
Checking coordinates [9, 18]
Checking coordinates [9, 17]
Checking coordinates [10, 17]
Checking coordinates [11, 17]
Checking coordinates [12, 17]
Checking coordinates [13, 17]
Checking coordinates [14, 17]
Checking coordinates [15, 17]
Checking coordinates [16, 17]
Checking coordinates [17, 17]
Checking coordinates [18, 17]
Checking coordinates [19, 17]
Checking coordinates [19, 18]
Checking coordinates [19, 19]
Checking coordinates [18, 19]
Checking coordinates [17, 19]
Checking coordinates [17, 16]
Checking coordinates [17, 15]
Checking coordinates [18, 15]
Checking coordinates [19, 15]
Checking coordinates [16, 15]
Checking coordinates [15, 15]
Checking coordinates [15, 14]
Checking coordinates [15, 13]
Checking coordinates [16, 13]
Checking coordinates [17, 13]
Checking coordinates [18, 13]
Checking coordinates [19, 13]
Checking coordinates [19, 12]
Checking coordinates [19, 11]
Checking coordinates [18, 11]
Checking coordinates [17, 11]
Checking coordinates [17, 10]
Checking coordinates [17, 9]
Checking coordinates [16, 9]
Checking coordinates [15, 9]
Checking coordinates [14, 9]
Checking coordinates [13, 9]
Checking coordinates [13, 8]
Checking coordinates [13, 7]
Checking coordinates [12, 7]
Checking coordinates [11, 7]
Checking coordinates [11, 6]
Checking coordinates [11, 5]
Checking coordinates [11, 4]
Checking coordinates [11, 3]
Checking coordinates [12, 3]
Checking coordinates [13, 3]
Checking coordinates [13, 2]
Checking coordinates [13, 1]
Checking coordinates [12, 1]
Checking coordinates [11, 1]
Checking coordinates [10, 1]
Checking coordinates [9, 1]
Checking coordinates [8, 1]
Checking coordinates [7, 1]
Checking coordinates [6, 1]
Checking coordinates [5, 1]
Checking coordinates [4, 1]
Checking coordinates [3, 1]
Checking coordinates [3, 2]
Checking coordinates [3, 3]
Checking coordinates [2, 3]
Checking coordinates [1, 3]
Checking coordinates [1, 2]
Checking coordinates [1, 1]
Checking coordinates [19, 10]
Checking coordinates [19, 9]
Checking coordinates [19, 8]
Checking coordinates [19, 7]
Checking coordinates [18, 7]
Checking coordinates [17, 7]
Checking coordinates [16, 7]
Checking coordinates [15, 7]
Checking coordinates [15, 6]
Checking coordinates [15, 5]
Checking coordinates [14, 5]
Checking coordinates [13, 5]
Checking coordinates [15, 4]
Checking coordinates [15, 3]
Checking coordinates [16, 3]
Checking coordinates [17, 3]
Checking coordinates [17, 2]
Checking coordinates [17, 1]
Checking coordinates [18, 1]
Checking coordinates [19, 1]
Checking coordinates [19, 2]
Checking coordinates [19, 3]
Checking coordinates [19, 4]
Checking coordinates [19, 5]
Checking coordinates [18, 5]
Checking coordinates [17, 5]
Checking coordinates [16, 1]
Checking coordinates [15, 1]
Checking coordinates [9, 4]
Checking coordinates [9, 3]
Checking coordinates [8, 3]
Checking coordinates [7, 3]
Checking coordinates [6, 3]
Checking coordinates [5, 3]
Checking coordinates [3, 14]
Checking coordinates [3, 15]
Checking coordinates [2, 15]
Checking coordinates [1, 15]
Checking coordinates [1, 16]
Checking coordinates [1, 17]
Checking coordinates [2, 17]
Checking coordinates [3, 17]
Checking coordinates [4, 17]
Checking coordinates [5, 17]
Checking coordinates [5, 16]
Checking coordinates [5, 15]
Checking coordinates [1, 18]
Checking coordinates [1, 19]
Checking coordinates [2, 19]
Checking coordinates [3, 19]
Checking coordinates [4, 19]
Checking coordinates [5, 19]
Checking coordinates [5, 20]
Path found:
 [0, 13]
 [1, 13]
 [2, 13]
 [3, 13]
 [3, 14]
 [3, 15]
 [2, 15]
 [1, 15]
 [1, 16]
 [1, 17]
 [1, 18]
 [1, 19]
 [2, 19]
 [3, 19]
 [4, 19]
 [5, 19]
 [5, 20]
alex@~/pathfinding$
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `pathfinding`
* File: `0-backtracking_array.c`
---
### [1. Backtracking - Graph](./1-backtracking_graph.c)

Write a function that searches for the first path from a starting point to a target point in a graph.

* Prototype:` queue_t *backtracking_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);`
* Where:
	* `graph` is a pointer to the graph to go through
	* `start` is a pointer to the starting vertex
	* `target` is a pointer to the target vertex
* Your function must return a queue, in which each node is a `char *` corresponding to a vertex, forming a path from `start`to `target` (See example)
* You’ll have to use recursive backtracking to find the first working path from `start` to `target`
* You’ll have to print each visited vertex as in the example below

```
alex@~/pathfinding$ cat 1-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
    printf("Path found:\n");
    while (path->front)
    {
        char *city = (char *)dequeue(path);
        printf(" %s\n", city);
        free(city);
    }
    free(path);
}

/**
 * main - A simple graph to test Backtracking algorithm
 *
 * Return: Either EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;
    vertex_t *start, *target;
    queue_t *path;

    graph = graph_create();
    graph_add_vertex(graph, "San Francisco", 0, 0);
    graph_add_vertex(graph, "Los Angeles", 0, 0);
    graph_add_vertex(graph, "Las Vegas", 0, 0);
    start = graph_add_vertex(graph, "Seattle", 0, 0);
    graph_add_vertex(graph, "Chicago", 0, 0);
    graph_add_vertex(graph, "Washington", 0, 0);
    graph_add_vertex(graph, "New York", 0, 0);
    graph_add_vertex(graph, "Houston", 0, 0);
    graph_add_vertex(graph, "Nashville", 0, 0);
    target = graph_add_vertex(graph, "Miami", 0, 0);
    graph_add_edge(graph, "San Francisco", "Los Angeles", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "San Francisco", "Las Vegas", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Los Angeles", "Las Vegas", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "San Francisco", "Seattle", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Seattle", "Chicago", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Chicago", "Washington", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Washington", "New York", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Las Vegas", "Houston", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Houston", "Nashville", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Nashville", "Washington", 0, BIDIRECTIONAL);
    graph_add_edge(graph, "Nashville", "Miami", 0, BIDIRECTIONAL);

    path = backtracking_graph(graph, start, target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);
    graph_delete(graph);

    return (EXIT_SUCCESS);
}
alex@~/pathfinding$ gcc -o 1-backtracking_graph -Wall -Wextra -Werror -pedantic 1-main.c 1-backtracking_graph.c -lqueues -lgraphs
alex@~/pathfinding$ ./1-backtracking_graph 
Checking Seattle
Checking San Francisco
Checking Los Angeles
Checking Las Vegas
Checking Houston
Checking Nashville
Checking Washington
Checking Chicago
Checking New York
Checking Miami
Path found:
 Seattle
 San Francisco
 Los Angeles
 Las Vegas
 Houston
 Nashville
 Miami
alex@~/pathfinding$ 
```

### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `pathfinding`
* File: `1-backtracking_graph.c`
---

### [2. Dijkstra's - Graph](./2-dijkstra_graph.c)

Write a function that searches for the shortest path from a starting point to a target point in a graph.

* Prototype: `queue_t *dijkstra_graph(graph_t *graph, vertex_t const *start, vertex_t const *target);`
* Where:
	* `graph` is a pointer to the graph to go through
	* `start` is a pointer to the starting vertex
	* `target` is a pointer to the target vertex
* Your function must return a queue, in which each node is a `char * `corresponding to a vertex, forming a path from `start` to `target` (See example)
* You’ll have to use Dijkstra’s algorithm to find the shortest path
* You’ll have to print each visited vertex as in the example below

```
alex@~/pathfinding$ cat 2-main.c 
#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
    printf("Path found:\n");
    while (path->front)
    {
        char *city = (char *)dequeue(path);
        printf(" %s\n", city);
        free(city);
    }
    free(path);
}

/**
 * main - A simple graph to test Dijkstra's algorithm
 *
 * Return: Either EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;
    vertex_t *start, *target;
    queue_t *path;

    graph = graph_create();
    graph_add_vertex(graph, "San Francisco", 0, 0);
    graph_add_vertex(graph, "Los Angeles", 0, 0);
    graph_add_vertex(graph, "Las Vegas", 0, 0);
    start = graph_add_vertex(graph, "Seattle", 0, 0);
    graph_add_vertex(graph, "Chicago", 0, 0);
    graph_add_vertex(graph, "Washington", 0, 0);
    graph_add_vertex(graph, "New York", 0, 0);
    graph_add_vertex(graph, "Houston", 0, 0);
    graph_add_vertex(graph, "Nashville", 0, 0);
    target = graph_add_vertex(graph, "Miami", 0, 0);
    graph_add_edge(graph, "San Francisco", "Los Angeles", 347, BIDIRECTIONAL);
    graph_add_edge(graph, "San Francisco", "Las Vegas", 417, BIDIRECTIONAL);
    graph_add_edge(graph, "Los Angeles", "Las Vegas", 228, BIDIRECTIONAL);
    graph_add_edge(graph, "San Francisco", "Seattle", 680, BIDIRECTIONAL);
    graph_add_edge(graph, "Seattle", "Chicago", 1734, BIDIRECTIONAL);
    graph_add_edge(graph, "Chicago", "Washington", 594, BIDIRECTIONAL);
    graph_add_edge(graph, "Washington", "New York", 203, BIDIRECTIONAL);
    graph_add_edge(graph, "Las Vegas", "Houston", 1227, BIDIRECTIONAL);
    graph_add_edge(graph, "Houston", "Nashville", 666, BIDIRECTIONAL);
    graph_add_edge(graph, "Nashville", "Washington", 566, BIDIRECTIONAL);
    graph_add_edge(graph, "Nashville", "Miami", 818, BIDIRECTIONAL);

    path = dijkstra_graph(graph, start, target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);
    graph_delete(graph);

    return (EXIT_SUCCESS);
}
alex@~/pathfinding$ gcc -o 2-dijkstra_graph -Wall -Wextra -Werror -pedantic 2-main.c 2-dijkstra_graph.c -lqueues -lgraphs
alex@~/pathfinding$ ./2-dijkstra_graph 
Checking Seattle, distance from Seattle is 0
Checking San Francisco, distance from Seattle is 680
Checking Los Angeles, distance from Seattle is 1027
Checking Las Vegas, distance from Seattle is 1097
Checking Chicago, distance from Seattle is 1734
Checking Houston, distance from Seattle is 2324
Checking Washington, distance from Seattle is 2328
Checking New York, distance from Seattle is 2531
Checking Nashville, distance from Seattle is 2894
Checking Miami, distance from Seattle is 3712
Path found:
 Seattle
 Chicago
 Washington
 Nashville
 Miami
alex@~/pathfinding$ 
```
Another example, to demonstrate Dijkstra’s weakness:

```
alex@~/pathfinding$ cat 2-main_1.c 
#include <stdlib.h>
#include <stdio.h>

#include "pathfinding.h"

/**
 * print_free_path - Unstacks the queue to discover the path from the starting
 * vertex to the target vertex. Also deallocates the queue.
 *
 * @path: Queue containing the path
 */
static void print_free_path(queue_t *path)
{
    printf("Path found:\n");
    while (path->front)
    {
        char *city = (char *)dequeue(path);
        printf(" %s\n", city);
        free(city);
    }
    free(path);
}

/**
 * main - Another example to demonstrate the weakness of Dijkstra's algorithm
 * In fact, Dijkstra's algorithm will always choose the shortest path from
 * the starting vertex.
 * In this example, the target vertex is just the neighbour of the starting
 * vertex, but the distance between them is very big. Dijkstra's algorithm will
 * then go through all the vertices, to finally fall back to the target vertex.
 *
 * Return: Either EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    graph_t *graph;
    vertex_t *start, *target;
    queue_t *path;

    graph = graph_create();
    start = graph_add_vertex(graph, "A", 0, 0);
    target = graph_add_vertex(graph, "B", 0, 0);
    graph_add_vertex(graph, "C", 0, 0);
    graph_add_vertex(graph, "D", 0, 0);
    graph_add_vertex(graph, "E", 0, 0);
    graph_add_vertex(graph, "F", 0, 0);
    graph_add_vertex(graph, "G", 0, 0);
    graph_add_vertex(graph, "H", 0, 0);
    graph_add_vertex(graph, "I", 0, 0);
    graph_add_vertex(graph, "J", 0, 0);
    graph_add_vertex(graph, "K", 0, 0);
    graph_add_vertex(graph, "L", 0, 0);
    graph_add_vertex(graph, "M", 0, 0);
    graph_add_vertex(graph, "N", 0, 0);
    graph_add_vertex(graph, "O", 0, 0);

    graph_add_edge(graph, "A", "B", 1000, BIDIRECTIONAL);
    graph_add_edge(graph, "A", "C", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "C", "D", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "D", "E", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "E", "F", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "F", "G", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "G", "H", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "H", "I", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "I", "J", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "J", "K", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "K", "L", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "L", "M", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "M", "N", 10, BIDIRECTIONAL);
    graph_add_edge(graph, "N", "O", 10, BIDIRECTIONAL);

    path = dijkstra_graph(graph, start, target);
    if (!path)
    {
        fprintf(stderr, "Failed to retrieve path\n");
        return (EXIT_FAILURE);
    }

    print_free_path(path);
    graph_delete(graph);

    return (EXIT_SUCCESS);
}
alex@~/pathfinding$ gcc -o 2-dijkstra_graph_1 -Wall -Wextra -Werror -pedantic 2-main_1.c 2-dijkstra_graph.c -lqueues -lgraphs
alex@~/pathfinding$ ./2-dijkstra_graph_1 
Checking A, distance from A is 0
Checking C, distance from A is 10
Checking D, distance from A is 20
Checking E, distance from A is 30
Checking F, distance from A is 40
Checking G, distance from A is 50
Checking H, distance from A is 60
Checking I, distance from A is 70
Checking J, distance from A is 80
Checking K, distance from A is 90
Checking L, distance from A is 100
Checking M, distance from A is 110
Checking N, distance from A is 120
Checking O, distance from A is 130
Checking B, distance from A is 1000
Path found:
 A
 B
alex@~/pathfinding$ 
```
### Repo:

* GitHub repository: `holbertonschool-system_algorithms`
* Directory: `pathfinding`
* File: `2-dijkstra_graph.c`
