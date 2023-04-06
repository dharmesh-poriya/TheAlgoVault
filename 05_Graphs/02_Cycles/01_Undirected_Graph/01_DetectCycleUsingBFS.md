# Detect Cycle in undirected graph using BFS
### [Problem Link](https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1)

## Approach-1 (Using parent node) : 
* create queue and push source node in it.
* create visited array and mark all nodes as unvisited.
* mark source node as visited.
* run a loop till queue is not empty.
* pop the front element from queue and print it.
* traverse all the adjacent nodes of the popped node.
* if the adjacent node is not visited then push it in the queue and mark it as visited.
* if the adjacent node is visited and it is not the parent of the popped node then return true.

## Code : 
```cpp
class Solution {
  public:
    bool bfs(vector<int> adj[],vector<bool> &vis,int src){
        queue<pair<int,int>> q;
        q.push({src,-1});
        vis[src] = true;
        while(!q.empty()){
            int u = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(int v : adj[u]){
                if(!vis[v]){
                    vis[v] = true;
                    q.push({v,u});
                }else if(parent!=v){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i] and bfs(adj,vis,i)){
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

## Approach-2 (using coloring) : 
* create queue and push source node in it.
* create visited array and mark all nodes as unvisited(0).
* mark source node as visited(1) and push it in the queue.
* run a loop till queue is not empty.
* pop the front element from queue and print it.
* traverse all the adjacent nodes of the popped node.
* if the adjacent node is not visited then push it in the queue and mark it as visited.(1).
* if the adjacent node is visited and it is not processed then return true.


## Code : 
```cpp
// 0 -> unvisited
// 1 -> visited
// 2 -> processed
class Solution {
  public:
    bool bfs(vector<int> adj[],vector<int> &vis,int src){
        queue<int> q;
        q.push(src);
        vis[src] ++;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int v : adj[u]){
                if(0==vis[v]){
                    vis[v] ++;
                    q.push(v);
                }else if(1==vis[v]){
                    return true;
                }
            }
            vis[u] = 2;
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i] and bfs(adj,vis,i)){
                return true;
            }
        }
        return false;
    }
};

```

#### Time Complexity : O(V+2E)
#### Space Complexity : O(V)