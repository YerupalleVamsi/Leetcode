class Solution {
public:
    int maximumLength(vector<int>& nums) {
        // odd  + odd  = even
        // even + even = even
        // odd  + even = odd
        // even + odd  = odd
        int e_cnt=0;
        int o_cnt=0;
        int max_cnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                o_cnt++;
            }
            else{
                e_cnt++;
            }
        }
        max_cnt=max(e_cnt,o_cnt);
    int count1 = 0; // For even-odd
    int expected1 = 0; // Start with even

    int count2 = 0; // For odd-even
    int expected2 = 1; // Start with odd

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] % 2 == expected1) {
            count1++;
            expected1 ^= 1; // Flip parity
        }
        if (nums[i] % 2 == expected2) {
            count2++;
            expected2 ^= 1;
        }
    }
    max_cnt=max(max_cnt,count1);
    max_cnt=max(max_cnt,count2);
    return max_cnt;

    }
};