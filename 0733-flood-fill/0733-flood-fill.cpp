class Solution
{
    public:
        int temp;
    void solve(vector<vector < int>> &image, vector< vector< int>> &flag, int sr, int sc, int color, int i, int j, int n, int m)
    {
        if (i < 0 || j < 0 || j >= m || i >= n || flag[i][j] == color || image[i][j] != temp) return;

        flag[i][j] = color;

        solve(image, flag, sr, sc, color, i + 1, j, n, m);
        solve(image, flag, sr, sc, color, i - 1, j, n, m);
        solve(image, flag, sr, sc, color, i, j - 1, n, m);
        solve(image, flag, sr, sc, color, i, j + 1, n, m);
        return;
    }
    vector<vector < int>> floodFill(vector<vector < int>> &image, int sr, int sc, int color)
    {
        temp = image[sr][sc];
        int n = image.size();
        int m = image[0].size();
        vector<vector < int>> flag(n, vector<int> (m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                flag[i][j] = image[i][j];
            }
        }
        solve(image, flag, sr, sc, color, sr, sc, n, m);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (image[i][j] < 0) image[i][j] = -image[i][j];
            }
        }
        return flag;
    }
};