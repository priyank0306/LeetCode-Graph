class Solution {
public:
  #define ll long long 
    int findCenter(vector<vector<int>>& edges) {
        ll n=edges.size();
      n++;
            
      ll temp=n;
      
      ll ans=0;
      
      n=(n*n)+n;
      n/=2;
      ll sum=0;
      for(int i=0; i<edges.size(); i++)
      {
        sum+=edges[i][0]+edges[i][1];
      }
      
      ans=sum-n;
      ans=ans/(temp-2);
      return ans;
      
    
      
    }
};