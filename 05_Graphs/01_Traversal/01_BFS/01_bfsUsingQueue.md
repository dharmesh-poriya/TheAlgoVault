# BFS Using Queue for Connected Undirected Graph
### [Problem Link](https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1)

## Approach (Iterative) : 
* create queue and push source node in it.
* create visited array and mark all nodes as unvisited.
* mark source node as visited.
* run a loop till queue is not empty.
* pop the front element from queue and print it.
* traverse all the adjacent nodes of the popped node.
* if the adjacent node is not visited then push it in the queue and mark it as visited.

## Code : 
```cpp
// n is total # of nodes in graph
// adj[] adjacency list of edges
// src : source node
vector<int> bfsOfGraph(int n, vector<int> adj[], int src = 0)
{
    vector<bool> vis(n, false);
    queue<int> q;
    q.push(src);
    vis[src] = true;
    vector<int> bfs;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        bfs.push_back(u);
        for (auto &v : adj[u])
        {
            if (!vis[v])
            {
                q.push(v);
                vis[v] = true;
            }
        }
    }
    return bfs;
}
```

#### Time Complexity : O(V+E) // V is # nodes and E is # of edges
#### Space Complexity : O(V) // assume that in a worst case all nodes connected with src node.

---


# Related Problems

<!-- <h3>
<details>
<summary>LeetCode</summary>

> ### 1. Problem: Name ( [Try It]() )

</details>
</h3> -->


<h3>
<details>
<summary>GFG</summary>

> ### 1. Shortest path in Undirected Graph having unit distance ( [Try It](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1) )

</details>
</h3>