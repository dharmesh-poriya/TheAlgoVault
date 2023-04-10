# Detect Cycle in a Directed Graph using DFS
### [Problem Link](https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1)

## Approach-01 (maintaining a visited array and a path visited array): 
* We will use a visited array to keep track of the nodes that are visited and a pathVis array to keep track of the nodes that are in the current path.
* We will start from each node and check if it is already visited or not. If it is not visited then we will call the dfs function on it's neighbours.
* If the neighbour is not visited then we will call the dfs function on it's neighbours and if it is visited then we will check if it is in the current path or not. If it is in the current path then we will return true else we will return false.


## Code : 
```cpp
// 
class Solution {
  public:
    bool dfs(vector<int> adj[],int src, vector<bool> &vis, vector<bool> &pathVis){
        pathVis[src] = vis[src] = true;
        for(int negh : adj[src]){
            if(!vis[negh]){
                if(dfs(adj,negh,vis,pathVis))
                    return true;
            }else if(pathVis[negh]){
                return true;
            }
        }
        pathVis[src] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> vis(V,false),pathVis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(dfs(adj,i,vis,pathVis))
                    return true;
            }
        }
        return false;
    }
};
```

#### Time Complexity : O(V + E) // V is the number of vertices and E is the number of edges
#### Space Complexity : O(2V)

---

## Approach-02 (maintaining a visited array): 
* We will use a visited array to keep track of the nodes that are visited.
* We will start from each node and check if it is already visited or not. If it is not visited then we will call the dfs function on it's neighbours.
* If the neighbour is not visited then we will call the dfs function on it's neighbours and if it is visited then we will return true.
* If the neighbour is visited and it is not in the current path then we will return false.

## Code : 
```cpp
// visited[i] = 0 -> not visited
// visited[i] = 1 -> visited
// visited[i] = 2 -> in the current path
class Solution {
  public:
    bool dfs(vector<int> adj[],int src, vector<int> &vis){
        vis[src] = 2;
        for(int negh : adj[src]){
            if(0==vis[negh]){
                if(dfs(adj,negh,vis))
                    return true;
            }else if(2==vis[negh]){
                return true;
            }
        }
        vis[src] = 1;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(0==vis[i]){
                if(dfs(adj,i,vis))
                    return true;
            }
        }
        return false;
    }
};
```

#### Time Complexity : O(V + E) // V is the number of vertices and E is the number of edges
#### Space Complexity : O(V)

---