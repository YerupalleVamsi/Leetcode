class Solution {
    private:
    bool check(vector<int>&nums,int m,int maxOperations){
            int op=0;
             for(int i:nums){
                if(i>m){
                    op+=(i-1)/m;
                }
            if(op>maxOperations)
            return false;
             }return true;
    }
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int right=*max_element(nums.begin(),nums.end());
        int left=1;
        while(left<right){
            int mid=(left+right)/2;
            if(check(nums,mid,maxOperations)){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
    }
};