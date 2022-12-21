// can we divide nodes in two graph or not so that no two adjacent node can have same group (check whether given graph is bipartite or not)
// https://leetcode.com/problems/possible-bipartition/

// BFS
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
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<char> colors(n+1,'0');
        vector<vector<int>> graph(n+1);
        for(auto d : dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        for(int i=1;i<n+1;i++){
            if('0'==colors[i])
                if(!bfs(graph,colors,i,'B'))
                    return false;
        }
        return true;
    }
};

// DFS 

class Solution {
    bool dfs(vector<vector<int>> &graph,vector<char> &colors,int src,char cc){
        colors[src] = cc;
        for(auto adj : graph[src]){
            if(cc==colors[adj] or ('0'==colors[adj] and !dfs(graph,colors,adj,('B'==cc?'R':'B')))) return false;
        }
        return true;
    }
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<char> colors(n+1,'0');
        vector<vector<int>> graph(n+1);
        for(auto d : dislikes){
            graph[d[0]].push_back(d[1]);
            graph[d[1]].push_back(d[0]);
        }
        for(int i=1;i<n+1;i++){
            if('0'==colors[i])
                if(!dfs(graph,colors,i,'B'))
                    return false;
        }
        return true;
    }
};