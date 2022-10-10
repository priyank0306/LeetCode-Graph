class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
       map<int,int>m;
      for(int i=0; i<edges.size(); i++)
      {
        m[edges[i][1]]++;
      }
      vector<int>ans;
      
         for(int i=0; i<n; i++)
      {
        if(m[i]==0)
          ans.push_back(i);
      }
    return ans;
    }
};