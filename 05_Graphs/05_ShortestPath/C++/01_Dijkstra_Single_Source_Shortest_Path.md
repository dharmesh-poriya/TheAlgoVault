# Dijkstra Algorithm (Single Source Shortest Path)
### [Problem Link]()

## Approach-01 (using Priority Queue) : 
* create a priority queue (Min Heap) to store the vertices and their distances from the source.
* create a vector to store the distances of all the vertices from the source.
* distance of source from itself is 0.
* distance of all other vertices from source is infinity.
* insert source in the priority queue.
* run a loop till the priority queue is not empty.
* extract the vertex with minimum distance from the priority queue.
* for each adjacent vertex of the extracted vertex, check if the distance of the adjacent vertex from the source is greater than the distance of the extracted vertex from the source + weight of the edge between them.
* if yes, update the distance of the adjacent vertex from the source.
* insert the adjacent vertex in the priority queue.
* return the vector containing the distances of all the vertices from the source.

## Note :
* Dijkstra will not work for negative weight edges.
* Dijkstra will not work for negative weight cycles.


## Code : 
```cpp
// V : number of vertices
// adj : adjacency list of the graph
// S : source vertex
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> dist(V,INT_MAX);
    dist[S] = 0;
    pq.push({0,S});
    
    while(!pq.empty()){
        auto curr = pq.top(); pq.pop();
        for(auto v : adj[curr.second]){
            if(dist[v[0]] > curr.first+v[1]){
                dist[v[0]] = curr.first+v[1];
                pq.push({dist[v[0]],v[0]});
            }
        }
    }
    return dist;
}
```

#### Time Complexity : O(E*log(V)) // E = number of edges, V = number of vertices
#### Space Complexity : O(E+V) // E = number of edges, V = number of vertices

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

> ### 1. Implementing Dijkstra Algorithm ( [Try It](https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1) )

</details>
</h3>