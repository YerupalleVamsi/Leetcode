class Solution {
public:
    void dfs(vector<vector<int>>&gr,vector<bool>&vis,int idx){
        vis[idx] = true;
        for(int i=0;i<gr.size();i++){
            if(gr[idx][i] && !vis[i]){
                dfs(gr,vis,i);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& gr) {
     int R =  gr.size();
    vector<bool>vis(R,false);
    int cnt=0;
     for(int i=0;i<R;i++){
        if(!vis[i]){
            dfs(gr,vis,i);
            cnt++;
        }
    }
    return cnt;}
};