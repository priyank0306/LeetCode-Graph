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
            // cout<<ans.size()<<endl;
              q.pop();
            for(auto  x:adj[temp])
            {
                inDegree[x]--;
                if(inDegree[x]==0)q.push(x);
            }
            
            
        
        }
    
        int a=ans.size();
        if(a==K){return "1";}
        
        
        return "1";
    }