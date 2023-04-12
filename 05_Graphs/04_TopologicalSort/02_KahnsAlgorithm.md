# Kahn's Algorithm for Topological Sort of a DAG (Directed Acyclic Graph)
### [Problem Link](https://practice.geeksforgeeks.org/problems/topological-sort/1)

## Approach (Iterative) : 
* Create a queue to store the nodes in the topological order.
* then first calculate the indegree of each node.
* then push all the nodes with indegree 0 in the queue.
* then pop the nodes from the queue and push them in the vector.
* then decrease the indegree of the neighbours of the popped node by 1.
* then indegree of the neighbour becomes 0 then we will push it in the queue.
* repeat the above steps until the queue is empty.

## Code : 
```cpp
// 
class Solution
{
	public:
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> toposort, indegree(V,0);
	    for(int u=0;u<V;u++)
	        for(int v : adj[u])
	            indegree[v]++;
	    
	    queue<int> q;
	    for(int u=0;u<V;u++)
	        if(0==indegree[u])
	            q.push(u);
	            
	   while(!q.empty()){
	       auto u = q.front(); q.pop();
	       toposort.push_back(u);
	       for(int v : adj[u]){
	           indegree[v]--;
	           if(0==indegree[v])
	               q.push(v);
	       }
	   }
	   return toposort;
	}
};
```

#### Time Complexity : O(V+E) // V is the number of vertices and E is the number of edges
#### Space Complexity : O(V)

---

# Related Problems

<!-- ### 1. LeetCode: Name ( [Try It]() ) -->
### 1. GFG: Detect cycle in a directed graph ( [Try It](https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1) )