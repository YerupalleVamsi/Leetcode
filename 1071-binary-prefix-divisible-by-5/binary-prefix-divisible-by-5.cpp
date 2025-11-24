class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size();
        vector<bool>res(n,0);
        int num = 0;
        for(int i=0;i<n;i++){
            num = (num * 2 + nums[i]) % 5;
            if(num==0){
                res[i]=1;
            }
        }
        return res;
    }
};