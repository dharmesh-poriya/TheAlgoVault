// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

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