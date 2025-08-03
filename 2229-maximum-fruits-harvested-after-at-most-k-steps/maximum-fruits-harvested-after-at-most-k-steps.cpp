class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n=fruits.size();
        int max_reach=max(fruits.back()[0],startPos+k);
        // the farthest
        vector<int>prefix(max_reach+2);
        for(int i=0;i<n;i++){
            int pos=fruits[i][0],val=fruits[i][1];
            prefix[pos+1]=val;
        }
        for(int i=1;i<=max_reach+1;i++){
            prefix[i]+=prefix[i-1];
        }
        int ans=0;
        for(int x=0;x<=k/2;x++){
            int r1=min(max_reach,startPos+x);
            int l1=max(0,startPos+x-(k-x));
            ans=max(ans,prefix[r1+1]-prefix[l1]);
            int l2=max(0,startPos-x);
            int r2=min(max_reach,startPos-x+(k-x));
            ans=max(ans,prefix[r2+1]-prefix[l2]);
        }
        return ans;
    }
};