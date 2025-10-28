class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& pre) {
        vector<vector<int>>adj(N);
        for(auto &it:pre){
            adj[it[1]].push_back(it[0]); 
        }
        vector<int>res;
        vector<int>indeg(N,0);
        queue<int>q;
        for (int u = 0; u < N; u++) {
        for (auto v : adj[u]) {
            indeg[v]++;
        }
        }

        for(int i=0;i<N;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto &it:adj[curr]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        if(res.size()==N){
            return res;
        }
        return {};
    }
};