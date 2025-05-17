class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0;
        int o=0;
        int t=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }
            if(nums[i]==1)
            o++;
            else
            t++;
        }
        fill(nums.begin(),nums.begin()+z,0);
        fill(nums.begin()+z,nums.begin()+z+o,1);
        fill(nums.begin()+z+o,nums.end(),2);
    }
};