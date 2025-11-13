class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int>dis(n,INT_MAX);
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:times){
            int  u = it[0]-1;
            int  v = it[1]-1; 
            int  w = it[2];
            adj[u].push_back({w,v});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k-1});
        dis[k-1] = 0;
        while(!pq.empty()){
            int dist =  pq.top().first;
            int curr = pq.top().second;
            pq.pop();
            if(dist > dis[curr]) continue;
            for(auto it:adj[curr]){
                int edge = it.first;
                if(edge+dist < dis[it.second]){
                    dis[it.second] = edge+dist;
                    pq.push({edge+dist,it.second});
                }
            }
        }
        int maxi = INT_MIN;
        for(int i:dis){
            if(i == INT_MAX) return -1;
            maxi =  max(maxi,i);
        }
        return maxi;
    }
};