void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &stk)
{
    visited[node] = true;
    for (auto it : adj[node])
        if (!visited[it])
            dfs(it, adj, visited, stk);
    stk.push_back(node);
}
vector<int> topoSortByDFS(int V, vector<int> adj[])
{
    // code here
    vector<bool> visited(V, false);
    vector<int> stk;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, stk);
    }

    reverse(stk.begin(), stk.end());
    return stk;
}