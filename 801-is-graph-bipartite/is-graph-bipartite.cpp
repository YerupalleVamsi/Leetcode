class Solution {
public:
    bool dfs(int idx,vector<int>&clr,vector<vector<int>>&graph,int paint){
        if(clr[idx]!=-1){
            if(paint == clr[idx]) return true;
            else
            return false;
        }
        clr[idx] = paint;
        
        for(int it: graph[idx]){ // toggle bru
           if(!dfs(it,clr,graph,1-paint)) return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int R = graph.size();
        vector<int>clr(R,-1);
        for(int i=0;i<R;i++){
            if(clr[i]==-1 && !dfs(i,clr,graph,0)){
                return false;
            }
        }
        return true;
    }
};