# Is Graph Bipartite? (Graph is undirected and disconnected)
### [Problem Link](https://leetcode.com/problems/is-graph-bipartite/)

## Approach-1 (BFS) : 
* We will use BFS to traverse the graph and color the nodes alternatively.
* If we find a node which is already colored with the same color as the current node, then the graph is not bipartite.
* If we find a node which is already colored with the opposite color as the current node, then we can ignore it.
* If we find a node which is not colored, then we will color it with the opposite color of the current node and push it into the queue. 
* We will repeat this process until the queue is empty.
* If we are able to color all the nodes, then the graph is bipartite.
* If we are not able to color all the nodes, then the graph is not bipartite.

## Code : 
```cpp
// vis[i] = 0 -> unvisited
// vis[i] = 1 -> visited and colored 1
// vis[i] = 2 -> visited and colored 2

class Solution {
    bool bfs(vector<vector<int>> &graph,vector<char> &colors,int src,char cc){
        colors[src] = cc;
        queue<pair<int,char>> q;
        q.push({src,cc});
        while(!q.empty()){
            auto current = q.front();
            q.pop();
            for(auto adj : graph[current.first]){
                if(current.second == colors[adj]) return false;
                if('0' == colors[adj]){
                    colors[adj] = ('B'==current.second?'R':'B');
                    q.push({adj,colors[adj]});
                } 
            }
        }
        return true;
    }
public:
    bool isBipartite(int n, vector<vector<int>>& graph) {
        vector<char> colors(n,'0');
        
        for(int i=0;i<n;i++){
            if('0'==colors[i])
                if(!bfs(graph,colors,i,'B'))
                    return false;
        }
        return true;
    }
};
```

#### Time Complexity : O(V+E) // V = number of vertices, E = number of edges
#### Space Complexity : O(V) 

---

## Approach-2 (DFS) : 
* We will use DFS to traverse the graph and color the nodes alternatively.
* If we find a node which is already colored with the same color as the current node, then the graph is not bipartite.
* If we find a node which is already colored with the opposite color as the current node, then we can ignore it.
* If we find a node which is not colored, then we will color it with the opposite color of the current node and push it into the queue.
* We will repeat this process until the stack is empty.
* If we are able to color all the nodes, then the graph is bipartite.
* If we are not able to color all the nodes, then the graph is not bipartite.

## Code : 
```cpp
// vis[i] = 0 -> unvisited
// vis[i] = 1 -> visited and colored 1
// vis[i] = 2 -> visited and colored 2

class Solution {
    bool dfs(vector<vector<int>> &graph,vector<char> &colors,int src,char cc){
        colors[src] = cc;
        for(auto adj : graph[src]){
            if(cc==colors[adj] or ('0'==colors[adj] and !dfs(graph,colors,adj,('B'==cc?'R':'B')))) return false;
        }
        return true;
    }
public:
    bool isBipartite(int n, vector<vector<int>>& graph) {
        vector<char> colors(n+1,'0');
        
        for(int i=0;i<n;i++){
            if('0'==colors[i])
                if(!dfs(graph,colors,i,'B'))
                    return false;
        }
        return true;
    }
};
```

#### Time Complexity : O(V+E) // V = number of vertices, E = number of edges
#### Space Complexity : O(V) 

---