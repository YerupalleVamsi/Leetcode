class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<vector<int>>res(n/3,vector<int>(3));
        int idx=0;
        for(int i=0;i<n;i+=3){
            if(nums[i+2]-nums[i]<=k){
                res[idx][0]=nums[i];
                res[idx][1]=nums[i+1];
                res[idx][2]=nums[i+2];
                idx++;
            }
            else
            return vector<vector<int>>(0);
        }
        return res;

    }
};