class Solution {
public:
int pairs(vector<int>&nums,int currdiff){
    int count=0;
    int i=0;
    int n=nums.size();
    while(i<n-1){
        if(nums[i+1]-nums[i]<=currdiff){
            count++;
            i+=2;
        }
        else i++;
    }
    return count;

}
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0)return 0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int low=0;
        int high=nums[n-1]-nums[0];
        while(low<high){
            int mid=low+(high-low)/2;
            if(pairs(nums,mid)>=p){
                high=mid;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};