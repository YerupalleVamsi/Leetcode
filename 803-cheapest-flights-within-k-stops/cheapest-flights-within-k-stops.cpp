class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
     vector<vector<pair<int,int>>>adj(n);
     for(auto it:flights){
        int u = it[0];
        int v = it[1];
        int edge = it[2];
        adj[u].push_back({v,edge});
     }   
    vector<int>dis(n,INT_MAX);
    queue<tuple<int,int,int>>pq;
    pq.push({0,src,0}); 
    while(!pq.empty()){
        auto [price,curr,curr_k]  = pq.front();pq.pop();
        if(curr_k>k) break;
        for(auto [next,cost]:adj[curr]){
            if(price+cost < dis[next]){
            dis[next] = price+cost;
            pq.push({price+cost,next,curr_k+1});
            }
        }
    }
     return dis[dst]==INT_MAX? -1:dis[dst];
    }
};