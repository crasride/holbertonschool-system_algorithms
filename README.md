<p align="center">
	<img src="./images/algo.webp" alt="">
</p>


<h1 align="center">Holberton School - System - Algorithms</h1>

[Project C - Red-Black trees](./red_black_tree/)

### Description

Red-Black trees are a type of `self-balancing binary search tree`. They maintain balance during `insertions` and `deletions`, ensuring efficient `search`, `insertion`, and `deletion operations` with a logarithmic time complexity. Red-Black trees are often used in scenarios where a balanced tree structure is crucial, such as in certain `database implementations` and `memory allocation algorithms`.

---

[Project C - Graphs](./graphs/)

### Description

Graphs represent a collection of `nodes` and `edges`, where `nodes` represent entities, and `edges` define relationships between them. Graph algorithms involve exploring or manipulating these relationships. Common graph algorithms include depth-first search `(DFS)` and breadth-first search `(BFS)`. Graphs find applications in various fields, such as `social network analysis`, `route planning`, and `network optimization`.

---

[Project C - Huffman coding](./huffman_coding/)

### Description

Huffman coding is a `compression algorithm` that assigns variable-length codes to input `characters` based on their `frequencies`. Characters with higher frequencies receive `shorter codes`, resulting in more efficient `compression`. Huffman coding is widely used in `data compression applications`, including `file compression` and `image encoding`. It is known for its simplicity and effectiveness in achieving `compression with minimal loss of information`.

<details>
<summary> **What is a binary heap (min and max):** </summary>
<br>
A binary heap is a specialized binary tree-based data structure that satisfies the heap property. In a min-heap, for every node i other than the root, the value of i is greater than or equal to the values of its children. This ensures that the smallest element is always at the root. Conversely, in a max-heap, for every node i other than the root, the value of i is less than or equal to the values of its children, ensuring that the largest element is at the root. Binary heaps are commonly used in algorithms that require efficient access to the minimum or maximum element, such as priority queues.
</details><

<details>
<summary>What is a priority queue:</summary><br>

A priority queue is an abstract data type that operates like a regular queue but assigns a priority level to each element. Elements with higher priority are dequeued before those with lower priority. Priority queues are commonly implemented using data structures like binary heaps, and they find applications in various algorithms, such as Dijkstra's algorithm for finding the shortest path and Huffman coding for data compression.
</details>

<details>
<summary>What is a Huffman code</summary><br>

Huffman coding is a compression algorithm used for lossless data compression. It is named after David A. Huffman, who developed the technique. Huffman coding assigns variable-length codes to input characters based on their frequencies in the input data. The more frequent characters are assigned shorter codes, while less frequent characters receive longer codes. This results in a prefix-free code, meaning no code is a prefix of another. Huffman coding is widely used in applications like file compression (e.g., in ZIP files) and is a fundamental concept in information theory.
</details>

---


[Project C - Pathfinding](./pathfinding/)

<details>
<summary>Click Description</summary> 

---

**What is pathfinding:**

Pathfinding is a computational technique used in computer science and artificial intelligence to find the most efficient route or path between two points within a network, graph, or grid. The goal is to determine the optimal way to navigate from a starting point to a destination while considering various constraints or costs associated with different paths.

**What are the most common applications of pathfinding:**

Pathfinding algorithms find widespread applications in various fields, such as robotics, video games, logistics, network routing, and navigation systems. They are essential for optimizing routes for vehicles, planning movements for characters in games, or determining efficient paths for delivery trucks.

**What is backtracking, and why you should never use it:**

Backtracking is a brute-force algorithmic technique where the system systematically explores all possible solutions to a problem by backtracking from suboptimal paths. While it can be effective for certain problems, it tends to be inefficient for many real-world scenarios due to its exhaustive nature. Backtracking may lead to high computational costs, especially when dealing with large search spaces, making it less practical for tasks like pathfinding in complex environments.

**What is Dijkstra’s algorithm, and what is its main weakness:**

Dijkstra's algorithm is a popular pathfinding algorithm used to find the shortest path between two nodes in a weighted graph. It works by iteratively selecting the node with the smallest known distance and updating the distances to its neighboring nodes. The main weakness of Dijkstra's algorithm is that it does not handle negative edge weights well. If a graph contains negative weights, the algorithm may produce incorrect results.

**What is A algorithm, and how is it better than Dijkstra’s:**

The A* (A-star) algorithm is another pathfinding algorithm that combines aspects of both Dijkstra's algorithm and greedy best-first search. A* takes into account both the cost of reaching a node from the start and a heuristic estimate of the cost to reach the goal. This makes A* more efficient than Dijkstra's algorithm in many cases, as it tends to explore paths that are more likely to lead to the optimal solution. A* is particularly useful when dealing with large graphs or grids, offering a balance between optimality and computational efficiency.
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
