class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        int l=0;
        for(int r=0;r<nums.size();r++){
            pq.push({nums[r],r});
            if(r-l+1==k){
                while(!pq.empty() && pq.top().second<l){
                    pq.pop();
                }
                res.push_back(pq.top().first);
                l++;
            }
        }
        return res;  
    }
};