class Solution {
public:
void dfs(vector<vector<int>>&isConnected,vector<int>&visited,int currentcity){
visited[currentcity]=1;
for(int i=0;i<isConnected.size();i++){
    if(isConnected[currentcity][i]==1&&visited[i]==0){
        dfs(isConnected,visited,i);
       
    }
}
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int>visited(isConnected.size(),0);
        int provinces=0;
          for (int i = 0; i < isConnected.size(); i++) {
            if (visited[i] == 0) {
                dfs(isConnected, visited, i);
                provinces++;
            }
        }
        
        return provinces;
        
    }
};
