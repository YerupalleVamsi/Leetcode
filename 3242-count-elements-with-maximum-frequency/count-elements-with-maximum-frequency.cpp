class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int>mpp;
        for(int i:nums)
        mpp[i]++;
        int maxi=INT_MIN;
        for(auto it:mpp){
            maxi=max(it.second,maxi);
            }
        int res=0;
        for(auto it:mpp){
            if(it.second==maxi){
                res+=it.second;
            }
        }

        return res;
    }
};