class Solution {
public:
    long long splitArray(vector<int>& nums) {
        long long res=0;
        int n=nums.size();
        int l=0;
        int r=n-1;
        long long r_sum=nums[n-1];
        long long l_sum=nums[0];
        while(l<n-1 && nums[l]<nums[l+1]){
            l++;
            l_sum+=nums[l];
            
        }
        while(r>0 && nums[r]<nums[r-1]){
            r--;
            r_sum+=nums[r];
        }
        if(l==r)
        return abs(max(r_sum,l_sum)-nums[l]-min(r_sum,l_sum));
        if(r==l+1){
            return abs(l_sum-r_sum);
        }
        return -1;

    }
};