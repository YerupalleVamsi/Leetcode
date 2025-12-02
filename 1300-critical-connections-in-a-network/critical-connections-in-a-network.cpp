class Solution {
public:
    int timer=1;
    void dfs(int curr,int parent,vector<vector<int>>&adj,vector<int>&tin,vector<int>&mint,vector<int>&vis,vector<vector<int>>&bridges){
        vis[curr]=1;
        tin[curr]  = timer;
        mint[curr] = timer;
        timer++;
        for(auto it:adj[curr]){
            if(it == parent) continue;
            if(vis[it]==-1){
                dfs(it,curr,adj,tin,mint,vis,bridges);
                mint[curr] = min(mint[curr],mint[it]);
                if(mint[it] > tin[curr]){
                    bridges.push_back({it,curr});
                }
            }
            else{
                mint[curr] = min(mint[curr],mint[it]);
            }
        }
        return;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int>tin(n);
        vector<int>mint(n);
        vector<int>vis(n,-1);
        vector<vector<int>>bridges;
        dfs(0,-1,adj,tin,mint,vis,bridges);
        return bridges;
    }
};