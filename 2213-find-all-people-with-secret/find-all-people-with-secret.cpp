class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it:meetings){
            adj[it[0]].push_back({it[2],it[1]});
            adj[it[1]].push_back({it[2],it[0]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>res;
        pq.push({0, 0});
        pq.push({0,firstPerson});
        vector<int>vis(n,0);
        while(!pq.empty()){
            auto [time , node] = pq.top();pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            for(auto [next_time,next_node]: adj[node]){
                if(!vis[next_node] && next_time>=time){
                pq.push({next_time,next_node});}
                
            }
        }
        res.push_back(0);
        for(int i=1;i<n;i++){
            if(vis[i]){
                res.push_back(i);
            }
        }
        return res;
    }
};