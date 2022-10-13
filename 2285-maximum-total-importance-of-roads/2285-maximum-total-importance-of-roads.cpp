class Solution
{
    public:
        long long maximumImportance(int n, vector<vector < int>> &roads)
        {
            long long int ans = 0;

            priority_queue<pair<int, int>, vector< pair<int, int>>> q;
            vector<int> count(n, 0);
            for (auto x: roads)
            {
                count[x[0]]++;
                count[x[1]]++;
            }
            int temp = n;
            for (int i = 0; i < n; i++)
            {
                q.push({ count[i],
                    i });
            }
            while (!q.empty())
            {

                pair<int, int> a = q.top();
                count[a.second] = temp; 
              temp--;
                q.pop();
            }
            for (int i = 0; i < n; i++) cout << count[i] << endl;
            for (int i = 0; i < roads.size(); i++)
            {
                ans = ans + count[roads[i][0]] + count[roads[i][1]];
            }

            return ans;
        }
};