class Solution {
public:
      map<int, set < int>> adj;
    bool solve(int start, int n, vector<int> &color)
    {
        queue<int> q;
        q.push(start);
        color[0] = 0;

        while (!q.empty())
        {

            int temp = q.front();

            q.pop();
            for (auto x: adj[temp])
            {

                if (color[x] == -1)
                {
                    q.push(x);

                    color[x] = !color[temp];
                }
                else if (color[x] == color[temp]) return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
      
        for(auto x:dislikes)
        {
           adj[x[0]].insert(x[1]);
                adj[x[1]].insert(x[0]);
        }
        bool ans = true;
        vector<int> color(n+1, -1);
        for (int i = 1; i < n+1; i++)
        {
            if (color[i] == -1)
                ans = ans &solve(i, n, color);
        }
        return ans;
    }
};