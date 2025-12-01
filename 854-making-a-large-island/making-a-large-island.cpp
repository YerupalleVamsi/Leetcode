class Solution {
public:
    class dsu{
        public: vector<int>size,parent;
        dsu(int n){
            parent.resize(n+1);
            size.resize(n+1,1);
            for(int i=0;i<=n;i++) parent[i]=i;
        }
        int find(int node){
            if(node == parent[node]) return node;
            return parent[node] =  find(parent[node]);
        }
        // by size
        void uni(int u, int v){
        int pu = find(u);
        int pv = find(v);
        if(pu == pv) return;
        if(size[pu] < size[pv]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
}

    };
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        dsu ds(n*n);
        int dirs[4][2] = {
            {1,0},
            {-1,0},
            {0,-1},
            {0,1}
        };
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    for(auto [nr,nc] : dirs){
                        int r = i+nr;
                        int c = j+nc;
                        if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==1){
                            int curr_key = i*n+j;
                            int neigh_key = r*n+c;
                            if(ds.find(curr_key)!=ds.find(neigh_key)){
                                ds.uni(curr_key,neigh_key);
                            }
                        }
                    }
                }
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int>s;
                    int cnt=1;
                    for(auto [nr,nc] : dirs){
                        int r = i+nr;
                        int c = j+nc;
                        if(r>=0 && c>=0 && r<n && c<n && grid[r][c]==1){
                            int neigh_key = r*n+c;
                            s.insert(ds.find(neigh_key));
                        }}
                    for(auto it:s){
                        cnt+=ds.size[it];
                    }
                    res=max(res,cnt);
                }
            }
        }
        return res == 0? n*n:res;
    }
};