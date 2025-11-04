class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        int sum=0;
        int n=nums.size();
        for(int i:nums)
        sum+=i;
        vector<int>res(n-k+1,0);
        for(int i=0;i<=n-k;i++){
        unordered_map<int,int>mpp;
        int sum =0 ;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int j=i;j<n && j<=i+k-1;j++){
            mpp[nums[j]]++;
            sum+=nums[j];
        }
        if(mpp.size() < x){res[i] = sum; continue;}
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        while(pq.size() > x){
            pq.pop();
        }
        int curr = 0;
        while(!pq.empty()){
            auto [freq,val] = pq.top();
            pq.pop();
            curr+= val * freq;
        }
        res[i] = curr;
        }
        return res;
    }
};