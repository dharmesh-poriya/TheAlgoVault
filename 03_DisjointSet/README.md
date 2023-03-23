<!--  write down readme file for disjoint set  -->
# Disjoint Set

### What is Disjoint Set?
* Disjoint Set is a data structure that keeps track of a set of elements partitioned into a number of disjoint (non-overlapping) subsets.
* A union-find algorithm is an algorithm that performs two useful operations on such a data structure:
    * Find: Determine which subset a particular element is in. This can be used for determining if two elements are in the same subset.
    * Union: Join two subsets into a single subset.

### Applications of Disjoint Set
* Kruskal's Minimum Spanning Tree Algorithm
* Cycle Detection in Undirected Graph
* Finding connected components in an undirected graph
* Finding connected components in a directed graph
* Finding the number of islands in a 2D matrix
* Finding the number of connected components in a 2D matrix
* Finding the number of strongly connected components in a directed graph
* Finding the number of connected components in a graph with self-loops
* Finding the number of connected components in a graph with multiple edges
* Finding the number of connected components in a graph with self-loops and multiple edges
* Finding the number of connected components in a graph with self-loops, multiple edges and cycles

## Functional Implementation
<h3>
<details>
<summary>Base Class for DSU</summary>

1.  <h3><a href='./01_BaseClass/00_DSU.md'>DSU (union is done by rank and size)</a></h3>
2.  <h3><a href='./01_BaseClass/01_DSUByParent.md'>DSU (union is done by only parent array)</a></h3>
3.  <h3><a href='./01_BaseClass/02_DSUByRank.md'>DSU (union is done by rank array)</a></h3>

</details>
<h3>
