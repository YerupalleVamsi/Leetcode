class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        int diff=0,maxi=0;
        for(int &i:nums){
            res=max(res,(long long)(diff)*i);
            diff=max(diff,maxi-i);
            maxi=max(maxi,i);
        }
        return res;
        
    }
};