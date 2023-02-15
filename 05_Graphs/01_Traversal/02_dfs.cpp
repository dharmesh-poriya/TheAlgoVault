private:
void dfs(vector<int> adj[], int src, vector<bool> &vis, vector<int> &ans)
{
    vis[src] = true;
    ans.push_back(src);
    for (int neighbours : adj[src])
    {
        if (!vis[neighbours])
        {
            dfs(adj, neighbours, vis, ans);
        }
    }
}

public:
// Function to return a list containing the DFS traversal of the graph.
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    vector<bool> vis(V + 1, false);
    vector<int> ans;
    dfs(adj, 0, vis, ans);
    return ans;
}