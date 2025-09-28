class Solution {
public:
    bool istriangle(int a,int b,int c){
        if(a+b>c && b+c>a && c+a>b) return true;
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        int res=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=n-1;i>=2;i--){
            if(istriangle(nums[i],nums[i-1],nums[i-2])){
                int sum=nums[i]+nums[i-1]+nums[i-2];
                res=max(res,sum);
            }
        }
        return res;
    }
};