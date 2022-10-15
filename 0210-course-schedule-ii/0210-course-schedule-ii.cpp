class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          map<int,vector<int>>adj;
         vector<int>inDegree(numCourses,0);
      for(auto x:prerequisites)
      {
      
        adj[x[1]].push_back(x[0]);
      }
	    for(int i=0; i<numCourses; i++)
	    {
	    for(auto x:adj[i])
	    {
	        inDegree[x]++;
	    }
	    }
	    queue<int>q;
	    vector<int>ans;
	   for(int i=0; i<numCourses; i++)
	   {
	       if(inDegree[i]==0)q.push(i);
	   }
	   while(!q.empty())
	   {
	       
	       int temp=q.front();
	       ans.push_back(temp);
	       
	       for(auto x:adj[temp])
	       {
	           inDegree[x]--;
	           if(inDegree[x]==0)q.push(x);
	       }
	       
	       q.pop();
	   }
	   map<int,int>m;
      for(int i=0; i<ans.size(); i++)
      {
        m[ans[i]]=i;
      }
      int flag=1;
      for(auto x: prerequisites)
      {
        if(m[x[0]]<m[x[1]])flag=0;
      }
      if(ans.size()==numCourses)
      return ans;
      
      ans.clear();
      return ans;
    }
};