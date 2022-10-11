class Solution
{
    public:
        bool canVisitAllRooms(vector<vector < int>> &rooms)
        {
            int n = rooms.size();
            vector<bool> vis(n, false);

            queue<int> q;
            q.push(0);
            vis[0] = true;
            while (!q.empty())
            {

                int temp = q.front();
                q.pop();
                vis[temp] = true;
                for (auto x: rooms[temp])
                {
                    if (vis[x] != true)
                    {
                        q.push(x);
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                if (vis[i] == false) return false;
            }
            return true;
        }
};