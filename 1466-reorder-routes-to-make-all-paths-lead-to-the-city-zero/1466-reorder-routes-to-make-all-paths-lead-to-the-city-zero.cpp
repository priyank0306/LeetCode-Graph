class Solution
{
    public:
        vector<int> adj[50002];
    int minReorder(int n, vector<vector < int>> &connections)
    {
        set<pair<int, int>> s;

        for (auto x: connections)
        {

            s.insert({ x[0],
                x[1] });
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        queue<int> q;
        q.push(0);

        vector<int> vis(n + 1, false);
        vis[0] = true;
        int count = 0;
        while (!q.empty())
        {

            int temp = q.front();
            q.pop();
            for (auto x: adj[temp])
                if (vis[x] != true)
                {
                    q.push(x);
                    vis[x] = true;
                    auto itr = s.find({ x,
                        temp });
                    if (itr == s.end())
                    {
                        count++;
                    }
                }
        }
        return count;
    }
};