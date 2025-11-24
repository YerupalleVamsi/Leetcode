class Solution {
public:
    void dfs(int i,vector<vector<int>>&adj,vector<int>&vis)
    {  if(vis[i]) return ;
    vis[i]=1;
        for(auto x:adj[i]){
            dfs(x,adj,vis);
        }

        return ;
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        vector<vector<int>>adj(n);
        vector<int>vis(n,0);
        for(auto it:connections){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }
        int cnt_cmp=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
            dfs(i,adj,vis);
            cnt_cmp++;
            }
        }
        if(connections.size() < n-1) return -1;
        return cnt_cmp-1;
    }
};