class Solution
{
    public:
        bool validPath(int n, vector<vector < int>> &edges, int source, int destination)
        {
            unordered_map<int, vector < int>> m;

            for (int i = 0; i < edges.size(); i++)
            {

                m[edges[i][0]].push_back(edges[i][1]);
                m[edges[i][1]].push_back(edges[i][0]);
            }
            vector<bool> vis(n, false);

            queue<int>q;
            q.push(source);
            vis[source] = true;
            while (!q.empty())
            {
                int temp = q.front();
              q.pop();
                for (auto x: m[temp])
                {
                    if (vis[x] != true)
                    {
                        q.push(x);
                        vis[x] = true;
                    }
                }
            }
            return vis[destination];
        }
};