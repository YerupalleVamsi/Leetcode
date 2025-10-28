class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& prereq) {
        vector<vector<int>>adj(N);
        for(auto&it:prereq){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>indeg(N,0);
        for(auto it: prereq){
            indeg[it[0]] ++ ;
        }
        vector<int>topo;
        queue<int>q;
        for (int i = 0; i < N; i++) {
        if (indeg[i] == 0) {
            q.push(i);
            }
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            topo.push_back(cur);
            for(int i:adj[cur]){
                indeg[i]--;
                if(indeg[i] == 0){
                    q.push(i);
                }
            }
        }
        return topo.size() == N ;
    }
};