vector<int> dfs(int V, vector<int> adj[])
{
    vector<bool> vis(V + 1, false);
    vector<int> ans;
    stack<int> st;
    vis[0] = true;
    st.push(0);
    while (!st.empty())
    {
        int node = st.top();
        vis[node] = true;
        ans.push_back(node);
        st.pop();
        for (int neighbours : adj[node])
        {
            if (!vis[neighbours])
            {
                vis[neighbours] = true;
                st.push(neighbours);
            }
        }
    }
    return ans;
}