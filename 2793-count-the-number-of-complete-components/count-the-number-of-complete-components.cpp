class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>graph(n);
        for(auto&e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool>visited(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(visited[i])continue;
            int nodes=0,degreeSum=0;
            dfs(i,graph,visited,nodes,degreeSum);
            if(degreeSum == nodes * (nodes-1)) cnt++;
        }
        return cnt;
    }

    void dfs( int curr , vector<vector<int>>&graph , vector<bool>&visited , int &nodes , int &degreeSum){
        visited[curr]=true;
        nodes++;
        degreeSum+=graph[curr].size();
        for(int v: graph[curr]){
            if(!visited[v]) 
           { dfs(v,graph,visited,nodes,degreeSum);}
        }
    }
};