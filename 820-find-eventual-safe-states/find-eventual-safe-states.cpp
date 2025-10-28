class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& gr) {
        int N = gr.size();
        vector<vector<int>>adj(N);
        for(int i=0;i<N;i++){
            for(auto v:gr[i]){
                adj[v].push_back(i);
            }
        }
        vector<int>res;
        vector<int>outdeg(N,0);
        queue<int>q;
        for (int u = 0; u < N; u++) {
        for (auto v : gr[u]) {
            outdeg[u]++;
        }
        }
        // cout << outdeg.size() << endl;
        // for(int i : outdeg)
        // cout <<  i << " ";

        // outdeg  -- 2 2 1 1 1 0 0

        for(int i=0;i<N;i++){
            if(outdeg[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for(auto &it:adj[curr]){
                outdeg[it]--;
                if(outdeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};