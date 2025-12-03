class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>pq;
        for(int i=0;i<nums2.size();i++){
            pq.push({nums1[0]+nums2[i],nums1[0],nums2[i],0});
        }
        vector<vector<int>>res;
        while(k--){
            auto[sum,x,y,idx]=pq.top();pq.pop();
            res.push_back({x,y});
            if(idx+1 < nums1.size())
            pq.push({nums1[idx+1]+y,nums1[idx+1],y,idx+1});
        }
        return res;
    }
};