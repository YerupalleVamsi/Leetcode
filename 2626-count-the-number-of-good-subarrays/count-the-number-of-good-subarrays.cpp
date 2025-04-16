class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long goodcount=0;
        int left=0;
        unordered_map<int,long long> freq;
        int freqcount=0;
        for(int right=0;right<nums.size();right++){
            freqcount+=freq[nums[right]];
            freq[nums[right]]++;
            while(freqcount>=k){
                goodcount+=nums.size()-right;
                freq[nums[left]]--;
                freqcount-=freq[nums[left]];
                left++;
            }
        }
        return goodcount;
    }
};