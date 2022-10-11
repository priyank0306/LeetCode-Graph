class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
      
      vector<int>temp1(n+1,0);
      vector<int>temp2(n+1,0);
      
      for(auto x:trust)
      {
            temp1[x[0]]++;
        temp2[x[1]]++;
      }
      for(int i=1; i<n+1; i++)
      {
        if(temp1[i]==0 && temp2[i]==n-1)return i;
      }
      return -1;
    }
};