<p align="center">
	<img src="./images/algo.webp" alt="">
</p>


<h1 align="center">Holberton School - System - Algorithms</h1>

## [Project C - Red-Black trees](./red_black_tree/)

### Description

Red-Black trees are a type of `self-balancing binary search tree`. They maintain balance during `insertions` and `deletions`, ensuring efficient `search`, `insertion`, and `deletion operations` with a logarithmic time complexity. Red-Black trees are often used in scenarios where a balanced tree structure is crucial, such as in certain `database implementations` and `memory allocation algorithms`.

<details>
<summary>What is a Red Black Tree:</summary>
<br>

A `Red-Black Tree `is a self-balancing binary search tree, which means it automatically maintains a balanced structure during insertions and deletions. It was named "`Red-Black`" due to the color-coding scheme used to balance the tree.

**Here are the key properties of a Red-Black Tree:**

*	`Binary Search Tree Property`:


	* Like any binary search tree, each node has at most two children, and for each node:
		* All nodes in its left subtree have keys less than the node's key.
		* All nodes in its right subtree have keys greater than the node's key.

*	`Coloring`:

	Each node in the tree is colored either red or black.
*	`Root and Leaves`:
	*	The root is always black.
	*	All leaves (null or sentinel nodes) are considered black.
*	`Red-Black Properties`:
	*	 No two adjacent (parent-child) nodes can be red.
	*	Every path from a node to its descendant leaves contains the same number of black nodes, ensuring a balanced height.
*	`Balancing Operations`:
	*	Insertion and deletion operations include additional steps to maintain the Red-Black properties.
	*	After insertion or deletion, the tree may need to be adjusted by rotating nodes and changing colors.

The self-balancing property of Red-Black Trees ensures that the height of the tree remains logarithmic, resulting in efficient search, insertion, and deletion operations. The worst-case time complexity for these operations is O(log n), where n is the number of nodes in the tree.

Red-Black Trees are commonly used in various applications, including the implementation of associative containers like sets and maps in programming languages and databases. The balanced nature of Red-Black Trees makes them suitable for scenarios where the tree structure needs to adapt dynamically to changing data.
</details>




## [Project C - Graphs](./graphs/)

### Description

Graphs represent a collection of `nodes` and `edges`, where `nodes` represent entities, and `edges` define relationships between them. Graph algorithms involve exploring or manipulating these relationships. Common graph algorithms include depth-first search `(DFS)` and breadth-first search `(BFS)`. Graphs find applications in various fields, such as `social network analysis`, `route 
planning`, and `network optimization`.

<details>
<summary>What is a graph:</summary>
<br>

In computer science and mathematics, a graph is a data structure that consists of a set of nodes (vertices) and a set of edges connecting pairs of nodes. Graphs are used to model relationships between entities, and they are widely employed in various applications, including network design, social network analysis, and route planning.


</details>

<details>
<summary>What are vertices and edges:</summary>


*	`Vertices (Nodes)`:
	These are the fundamental units in a graph, representing entities or points in the graph.

*	`Edges`:
	These are the connections between vertices, representing relationships or links. Edges may be directed or undirected, and they may have weights.


</details>

<details>
<summary>Types of Graphs:</summary>
<br>

*	`Directed Graph (Digraph)`:
	Edges have a direction, indicating a one-way relationship.
*	`Undirected Graph`:
	Edges have no direction; relationships are symmetric.
*	`Weighted Graph`:
	Each edge has an associated weight or cost.
*	`Cyclic Graph`:
	Contains at least one cycle (a path that starts and ends at the same vertex).
*	`Acyclic Graph`:
	Contains no cycles.
*	`Connected Graph`:
	There is a path between every pair of vertices.
*	`Disconnected Graph`:
		Contains at least two vertices without a connecting path.
*	`Bipartite Graph`:
	Vertices can be divided into two sets, with edges connecting only between sets.

</details>

<details>
<summary>Representing Graphs in C:</summary>
<br>

*	`Adjacency Matrix`:
	A 2D array where `graph[i][j]` is 1 if there is an edge between vertices `i` and `j`.
*	`Adjacency List`:
	An array of lists, where each element in the array represents a vertex, and its corresponding list contains all adjacent vertices.

</details>

<details>
<summary>Traversing a Graph using DFS and BFS:</summary>
<br>

*	`Depth-First Search (DFS)`:

	* Start at a source vertex and explore as far as possible along each branch before backtracking.
	* Uses a stack or recursion.
	* Typically implemented using recursion in C.

*	`Breadth-First Search (BFS)`:
	* Explore all vertices at the current level before moving on to the next level.
	* Uses a queue.
	* Queue data structure may be implemented using arrays or linked lists in C.

</details>




## [Project C - Huffman coding](./huffman_coding/)

### Description

Huffman coding is a `compression algorithm` that assigns variable-length codes to input `characters` based on their `frequencies`. Characters with higher frequencies receive `shorter codes`, resulting in more efficient `compression`. Huffman coding is widely used in `data compression applications`, including `file compression` and `image encoding`. It is known for its simplicity and effectiveness in achieving `compression with minimal loss of information`.

<details>
<summary>What is a binary heap (min and max):</summary>
<br>

A `binary heap `is a specialized binary tree-based data structure that satisfies the heap property. In a min-heap, for every node i other than the root, the value of i is greater than or equal to the values of its children. This ensures that the smallest element is always at the root. Conversely, in a max-heap, for every node i other than the root, the value of i is less than or equal to the values of its children, ensuring that the largest element is at the root. Binary heaps are commonly used in algorithms that require efficient access to the minimum or maximum element, such as priority queues.

</details>

<details>
<summary>What is a priority queue:</summary>
<br>

A `priority queue` is an abstract data type that operates like a regular queue but assigns a priority level to each element. Elements with higher priority are dequeued before those with lower priority. `Priority queues` are commonly implemented using data structures like `binary heaps`, and they find applications in various algorithms, such as `Dijkstra's` algorithm for finding the `shortest path` and Huffman coding for data compression.

</details>

<details>
<summary>What is a Huffman code</summary>
<br>

`Huffman` coding is a compression algorithm used for lossless data compression. It is named after David A. Huffman, who developed the technique. Huffman coding assigns `variable-length` codes to input `characters` based on their `frequencies` in the input data. The more frequent characters are assigned shorter codes, while less frequent characters receive longer codes. This results in a prefix-free code, meaning no code is a prefix of another. `Huffman` coding is widely used in applications like file compression (e.g., in ZIP files) and is a fundamental concept in information theory.

</details>



## [Project C - Pathfinding](./pathfinding/)

### Description

<details>
<summary>What is pathfinding:</summary> 
<br>

`Pathfinding` is a computational technique used in computer science and artificial intelligence to find the `most efficient` route or `path` between two points within a `network, graph, or grid`. The goal is to determine the optimal way to navigate from a starting point to a destination while considering various constraints or costs associated with different paths.

</details>

<details>
<summary>What are the most common applications of pathfinding:</summary>
<br>

`Pathfinding` algorithms find widespread applications in various fields, such as robotics, video games, logistics, network routing, and navigation systems. They are essential for `optimizing` `routes` for vehicles, `planning` movements for characters in `games`, or determining efficient paths for delivery trucks.<br>

</details>


<details>
<summary>What is backtracking, and why you should never use it:</summary>
<br>

`Backtracking` is a `brute-force` algorithmic technique where the system systematically explores all possible solutions to a problem by `backtracking` from `suboptimal paths`. While it can be effective for certain problems, it tends to be inefficient for many real-world scenarios due to its exhaustive nature. `Backtracking` may lead to high computational costs, especially when dealing with large search spaces, making it less practical for tasks like pathfinding in complex environments.

</details>


<details>
<summary>What is Dijkstra’s algorithm, and what is its main weakness:</summary>
<br>

`Dijkstra's` algorithm is a popular `pathfinding` algorithm used to find the shortest path between two nodes in a weighted graph. It works by iteratively selecting the node with the `smallest` known `distance` and updating the distances to its neighboring nodes. The main weakness of `Dijkstra's`algorithm is that it does not handle negative edge weights well. If a graph contains negative weights, the algorithm may produce incorrect results.

</details>


<details>
<summary>What is A algorithm, and how is it better than Dijkstra’s:</summary>
<br>

The `A* (A-star)` algorithm is another pathfinding algorithm that combines aspects of both `Dijkstra's `algorithm and greedy best-first search. `A*` takes into account both the cost of reaching a node from the start and a heuristic estimate of the cost to reach the goal. This makes `A*` more efficient than `Dijkstra's` algorithm in many cases, as it tends to explore paths that are more likely to lead to the optimal solution. `A*` is particularly useful when dealing with `large graphs` or `grids`, offering a balance between `optimality` and computational `efficiency`.

</details>

## [Project C - N-ary trees](./nary_trees/)

### Description

<details>
<summary>What is a N-ary tree</summary> 
<br>
	An N-ary tree is a tree data structure in which each node can have at most N children. Unlike a binary tree, where each node can have at most two children (left and right), an N-ary tree allows each node to have more than two children. The value of N in an N-ary tree is the maximum number of children a node can have.

</details>

### Description

<details>
<summary>What are the most common usage of N-ary trees</summary>
<br>

1. **File Systems:**

	* N-ary trees are often used to represent file systems. Each directory can have multiple subdirectories, making it a natural fit for an N-ary tree structure.

2. **Organization Structures:**

	* Representing organizational structures in a business or hierarchy, where each employee (node) can have multiple subordinates.

3. **Syntax Trees:**

	* In linguistics and compilers, N-ary trees are used to represent the hierarchical structure of sentences or programming language constructs.

4. **Decision Trees:**

	* Representing multiway decisions in decision trees, where each internal node represents a decision with multiple outcomes.

</details>

### Description

<details>
<summary>How to represent an N-ary tree in C in at least two different ways</summary> 
<br>

1. **Array-Based Representation:**

	*	In this approach, you can use a one-dimensional array to represent the nodes of an N-ary tree. The relationship between nodes is determined by the index of the array elements. For a node at index i, its children can be found at indices `N*i + 1` through `N*i + N.`

2. **Linked Representation:**

	*	Another way is to use a linked representation, where each node in the N-ary tree is a struct containing data and a list of pointers to its children. This involves dynamically allocating memory for each node and linking them together.

</details>

### Description

<details>
<summary>What is the diameter of an N-ary tree</summary> 
<br>

The diameter of an N-ary tree is defined as the length of the longest path between any two nodes in the tree. This path does not necessarily need to pass through the root. Calculating the diameter involves finding the maximum depth of the tree starting from each node and determining the maximum distance between two nodes.

For more details on how to calculate the diameter of an N-ary tree, you can refer to specific algorithms and resources mentioned earlier. The process involves traversing the tree and keeping track of the maximum path length encountered.
</details>

## Author

* José Fernàndez Armas

<sub>_You can contact me_ 📩

[Fernandez Armas José](https://github.com/crasride)

<p align="left">
<a href="https://twitter.com/JosFern35900656" target="blank"><img align="center" src="./images/twitter.svg" alt="crasride" height="30" width="40" /></a>
<a href="https://www.linkedin.com/in/jd-fernandez/" target="blank"><img align="center" src="./images/linked-in-alt.svg" alt="crasride" height="30" width="40" /></a>
<a href="https://medium.com/@4990" target="blank"><img align="center" src="./images/medium.svg" alt="@crasride" height="30" width="40" /></a>
<a href="https://discord.gg/José Fernandez Armas#7992" target="blank"><img align="center" src="./images/discord.svg" alt="crasride" height="30" width="40" /></a>
</p>
