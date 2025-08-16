class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<long long>res;
        unordered_map<int,long long>mpp;
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            p.push_back({nums1[i],i});
        }
        sort(p.begin(),p.end());
        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum=0;
        int j=0;
        for(int i=0;i<n;i++){
            int curr_idx=p[i].second;
            while(j<i){
                int prev=p[j].second;
                if(p[j].first >= p[i].first) break;
                pq.push(nums2[prev]);
                sum+=nums2[prev];
                if(pq.size()>k){
                    sum-=pq.top();
                    pq.pop();
                }
            j++;
            }
            mpp[curr_idx]=sum;
        }
        for(int i=0;i<n;i++){
            res.push_back(mpp[i]);
        }
        return res;

    }
};