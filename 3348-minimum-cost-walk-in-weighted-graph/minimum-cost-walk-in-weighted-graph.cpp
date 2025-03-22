class Solution {
public:
    void dfs(int node, vector<vector<int>>&gr , vector<int> &vis , int compNum , unordered_map<int,int>&nodeToComp){
        vis[node]=1;
        nodeToComp[node]=compNum; // marked component number
        for(auto ne: gr[node]){
            if(!vis[ne])
            dfs(ne,gr,vis,compNum,nodeToComp);
        }
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        int e=edges.size();
        vector<vector<int>>gr(n,vector<int>(0));
        for(int i=0;i<e;i++){
            int u=edges[i][0], v=edges[i][1];
            gr[u].push_back(v);
            gr[v].push_back(u);
        }
        // graph ni build chessam adj matrix

        unordered_map<int,int> nodeToComp; // node's component number
        int compNum=1; // the first component starts with 1 right
        vector<int> visited(n,0); 
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,gr,visited,compNum,nodeToComp);
                compNum++; // changing the component number
            }
        }

        vector<int>compScore(n,pow(2,31)-1); // intialising with max score 
        for(int i=0;i<e;i++){
            int u=edges[i][0],v=edges[i][1];
            int uComp=nodeToComp[u];
            compScore[uComp]=compScore[uComp] & edges[i][2];
        }

        vector<int> ans;
        int q=query.size();
        for(int i=0;i<q;i++){
            if(query[i][0]==query[i][1]){
                ans.push_back(0);  // edge case
            }
            else if(nodeToComp[query[i][0]]== nodeToComp[query[i][1]]){
                ans.push_back(compScore[nodeToComp[query[i][0]]]);
            }
            else{
                ans.push_back(-1);
            }
        }
        return ans;
    }
};