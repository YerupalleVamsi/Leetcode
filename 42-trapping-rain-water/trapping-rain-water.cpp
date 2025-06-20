/*int n=nums.size();
        int res=0;
        for(int i=0;i<n;i++){
            int l_max=nums[i];
            int r_max=nums[i];
            for(int l=i;l>=0;l--){
                l_max=max(l_max,nums[l]);
            }
            for(int r=i;r<n;r++){
                r_max=max(r_max,nums[r]);
            }
            res+=min(l_max,r_max)-nums[i];
        }
        return res;*/  // [323/324] why nigga that one tc
 


class Solution {
public:
    int trap(vector<int>&nums) {
        // so we have to precompute i guess
        int n=nums.size();
        vector<int>pre(n);
        vector<int>suf(n);
        pre[0]=nums[0];
        suf[n-1]=nums[n-1];
        for(int l=1;l<n;l++){
            pre[l]=max(pre[l-1],nums[l]);
        }
        for(int r=n-2;r>=0;r--){
            suf[r]=max(suf[r+1],nums[r]);
        }
        int water=0;
        for(int i=0;i<n;i++){
            water+=min(pre[i],suf[i])-nums[i];
        }
        return water;

    }
};