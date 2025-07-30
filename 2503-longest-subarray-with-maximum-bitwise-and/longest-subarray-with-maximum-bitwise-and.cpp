/*class Solution {
public:
    // what I have observed :
    // the bit wise & of any two numbers never increases it always decreases 
    // so what i think from this is a & b <= min(a,b) we got an obseravation nigga
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mpp;
        int max_num=INT_MIN;
        for(int i:nums){
            mpp[i]++;
            max_num=max(max_num,i);
        }
        return mpp[max_num];

    }
};*/ 
// haha got me i thought it was a subsequence 
// lets make soln for a subarray 
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int max_num=INT_MIN;
        for(int i:nums)
        max_num=max(max_num,i);
        int max_len=0;
        int curr_len=0;
        for(int i:nums){
            if(i==max_num){
                curr_len++;
                max_len=max(curr_len,max_len);
            }
            else{
                
                curr_len=0;
            }
        }
        return max_len;

    }
};