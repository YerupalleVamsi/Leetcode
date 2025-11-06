class Solution {
public:
    void makecomp(vector<vector<int>>&adj,vector<bool>&vis,int i,set<int>&comp){
        vis[i] = true;
        comp.insert(i);
        for(int n : adj[i]){
            if(!vis[n]){
                makecomp(adj,vis,n,comp);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& q) {
        vector<int>res;
        vector<vector<int>>adj(c);
        unordered_map<int,set<int>>cmpp;
        for(auto it:connections){
            int u = it[0]-1;
            int v = it[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool>vis(c,false);
        int cnt = 0;
        for(int i=0;i<adj.size();i++){
            if(!vis[i]){
                set<int>comp;
                makecomp(adj,vis,i,comp);
                cnt++;
                cmpp[cnt] = comp;
            }
        }
        unordered_map<int,int>mpp; // node to comp
        for(auto it:cmpp){
            int comp_num = it.first;
            for(auto cm: it.second){
                mpp[cm] = comp_num;
            }
        }
        

           for (auto& it : q) {
            int y = it[0];
            int x = it[1] - 1; 

            if (y == 1) {
                if (mpp.find(x) == mpp.end()) {
                    res.push_back(-1);
                } else {
                    int cmp = mpp[x];
                    if (!cmpp[cmp].empty()) {  
                        if (cmpp[cmp].count(x))
                            res.push_back(x);
                        else
                            res.push_back(*cmpp[cmp].begin());
                    } else {
                        res.push_back(-1);
                    }
                }
            } else {
                if (mpp.find(x) != mpp.end()) {
                    int cmp = mpp[x];
                    cmpp[cmp].erase(x);
                }
            }
        }
        for(int i=0;i<res.size();i++){
            if(res[i]!=-1)
            res[i]+=1;
        }
        return res;
    }
};