class Solution {
public:
  int n;
  void dfs(vector<int>& temp,vector<int>& vis,int i,vector<vector<int>>& isConnected)
  {
    for(int i=0; i<n; i++)
    {
      if(temp[i]==1 && vis[i]!=true)
      {
        vis[i]=true;
        dfs(isConnected[i],vis,i,isConnected);
      }
    }
    return;
  }
    int findCircleNum(vector<vector<int>>& isConnected) {
       n=isConnected.size();
      vector<int>vis(n,false);
      int count=0;
      
      for(int i=0; i<n; i++)
      {
        if(vis[i]!=true)
        {
          count++;
          vis[i]=true;
          dfs(isConnected[i],vis,i,isConnected);
          
        }
      }
      return count;
    }
};