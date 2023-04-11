# Topological Sort of a DAG (Directed Acyclic Graph) using DFS
### [Problem Link](https://practice.geeksforgeeks.org/problems/topological-sort/1)

## Approach (Recursive) : 
* We will use a stack to store the nodes in the topological order.
* We will start from each node and check if it is already visited or not. If it is not visited then we will call the dfs function on it's neighbours.
* If the neighbour is not visited then we will call the dfs function on it's neighbours and if it is visited then we will return.
* After the dfs function call is over we will push the current node in the stack.


## Code : 
```cpp
// 
class Solution
{
	public:
	void dfs(vector<int> adj[],int src,vector<bool> &vis,stack<int> &st){
	    vis[src] = true;
	    
	    for(int v : adj[src]){
	        if(!vis[v]){
	            dfs(adj,v,vis,st);
	        }
	    }
	    
	    st.push(src);
	    return;
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> vis(V,false);
	    vector<int> ans;
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]){
	            dfs(adj,i,vis,st);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
```

#### Time Complexity : O(V+E)
#### Space Complexity : O(V)

---

# Related Problems

<!-- ### 1. LeetCode: Name ( [Try It]() )
### 1. GFG: Name ( [Try It]() ) -->