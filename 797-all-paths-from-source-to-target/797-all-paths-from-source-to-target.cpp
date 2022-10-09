class Solution
{
    public:
        vector<vector < int>> ans;
    
    void dfs(vector<vector < int>> &graph, vector< int >& path, int curr, int n)
    {
      path.push_back(curr);

       if(curr==n-1){
         ans.push_back(path);
      
       }
      else
      {
        for(auto x:graph[curr])
        {
          dfs(graph,path,x,n);
        }
      }
      path.pop_back();
    }

    vector<vector < int>> allPathsSourceTarget(vector<vector < int>> &graph)
    {

        vector<int> path;
        int n = graph.size();
      
        dfs(graph, path, 0, n);

        return ans;
    }
};