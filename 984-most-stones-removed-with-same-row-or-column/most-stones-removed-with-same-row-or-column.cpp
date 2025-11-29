class Solution {
public:
    class dsu{
        public : unordered_map<int,int>mpp;
        int find(int x){
            if(!mpp.count(x)) mpp[x]=x;
            if(mpp[x] == x) return x;
            return mpp[x] = find(mpp[x]);
        }
        void un(int u,int v){
            u  = find(u);
            v  = find(v);
            if(u!=v){
                mpp[v] = u;
            }}
        };
    int removeStones(vector<vector<int>>& stones) {
        unordered_set<int>s;
        int cnt=0;
        dsu d;
        for(auto it:stones){
            int r = it[0];
            int c = ~it[1];
            d.un(r,c);
            s.insert(r);
            s.insert(c);
        }
        for(auto it:s){
            if(d.find(it)==it) cnt++;
        }
        return stones.size()-cnt;
    }
};