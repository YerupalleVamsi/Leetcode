class Solution {
public:
bool hasNextPermutation(vector<int>& nums) {
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--) {
        if (nums[i] < nums[i + 1]) {
            return true; 
        }
    }
    return false; 
}


int nextpermutation(vector<int>&nums){
    int n=nums.size();
   int i=n-2;
   while(i>=0 && nums[i]>=nums[i+1]){
    i--;
   }
   if(i<0){
    return -1;
   }
   int j=n-1;
   while(nums[j]<=nums[i]){
    j--;
   }
   swap(nums[i],nums[j]);
   sort(nums.begin()+i+1,nums.end());
   long long num=0;
   for(int d: nums){
    num=num*10+d;
    if(num>INT_MAX)
    return -1;
   }
   return (int)num;
}


    int nextGreaterElement(int n) {
        vector<int>nums;
        if (n>INT_MAX)
        return -1;
        while(n>0){
           int digit=n%10;
            n=n/10;
            nums.push_back(digit);
        }
         reverse(nums.begin(), nums.end());
        if (hasNextPermutation(nums)){
            return nextpermutation(nums);
        }
        return -1;
    }
};