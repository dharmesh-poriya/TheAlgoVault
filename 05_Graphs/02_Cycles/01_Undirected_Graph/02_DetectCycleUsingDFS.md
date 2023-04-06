# Detect Cycle in undirected graph using DFS
### [Problem Link](https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

## Approach-1 (Using parent node and recursion) : 
* call dfs function for each node.
* if the node is not visited then mark it as visited and call dfs for all its adjacent nodes.
* if the adjacent node is visited and it is not the parent of the current node then return true.

## Code : 
```cpp
class Solution {
  public:
    bool dfs(vector<int> adj[],vector<bool> &vis,int src,int parent){
        vis[src] = true;
        for(int v : adj[src]){
            if(!vis[v]){
                if(dfs(adj,vis,v,src)) return true;
            }else if(parent!=v){
                return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] and dfs(adj,vis,i,-1)){
                return true;
            }
        }
        return false;
    }
};

```

#### Time Complexity : O(V+2E)
#### Space Complexity : O(V)

---