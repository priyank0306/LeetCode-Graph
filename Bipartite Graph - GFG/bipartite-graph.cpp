//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:

 bool solve(int start,int n,vector<int>adj[],vector<int>& color)
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
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    bool ans=true;
	    vector<int> color(V, -1);
	    for(int i=0; i<V; i++)
	    {
	        if(color[i]==-1)
	    ans=ans&solve(i,V,adj,color);
	    }
return ans;
	    
	   
	    
	      
        
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends