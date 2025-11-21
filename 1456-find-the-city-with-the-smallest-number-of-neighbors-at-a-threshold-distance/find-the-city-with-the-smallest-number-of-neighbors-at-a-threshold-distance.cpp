class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int T) {
        vector<vector<int>>dis(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dis[i][j]=0;
            }
        }
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            dis[u][v] = w;
            dis[v][u] = w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++){
                    dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    int res = INT_MAX;
    int node = INT_MIN;
    for(int i=0;i<n;i++){
        int reachable=0;
        for(int j=0;j<n;j++){
            if(dis[i][j]!=1e9 && dis[i][j] <= T){
                reachable++;
            }
        }
        if(reachable <= res){
            res=reachable;
            if(node < i){
                node=i;
            }
        }
    }
    return node;
    }
};