//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int N, int K) {
               vector<int>inDegree(K,0);
    
        map<int,vector<int>>adj;
        queue<int>q;
        
        for(int i=1; i<N; i++){
            
            int  j=0;
            int k=0;
            
            while(j<dict[i-1].length() && k<dict[i].length())
            { 
                
                if(dict[i-1][j]!=dict[i][k])
                {
                    adj[dict[i-1][j]-'a'].push_back(dict[i][k]-'a');
                    break;
                }
                j++;k++;
            }
        
        }
        for(int i=0; i<K; i++)
        {
            for(auto x:adj[i])
            {
                inDegree[x]++;
            }
        }
        
        for(int i=0; i<K; i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty())
        {
            int temp=q.front();
            
            ans.push_back(temp);
        
              q.pop();
            for(auto  x:adj[temp])
            {
                inDegree[x]--;
                if(inDegree[x]==0)q.push(x);
            }
            
            
        
        }
    
        int a=ans.size();
        
        
        
        string final="";
        for(auto x:ans)
        {
            final+=char(x+'a');
        }
    return final;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends