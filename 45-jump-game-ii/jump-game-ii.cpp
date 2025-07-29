/*class Solution {
public:
    int backtrack(vector<int>&nums,int curr,int steps){
        if(curr>=nums.size()-1){
            return steps;
        }
        int max_jump=min((int)nums.size()-1,curr+nums[curr]);
        int min_steps=INT_MAX;
        for(int i=curr+1;i<=max_jump;i++){
            min_steps=min(min_steps,backtrack(nums,i,steps+1));
        }
        return min_steps;
    }
    int jump(vector<int>& nums) {
        return backtrack(nums,0,0);
    }
};*/   
// ----> TLE[74/110] backtracking
class Solution {
public:
    int jump(vector<int>& nums) {
        // lets be greedy nigga
        int l=0;
        int r=0;
        int jumps=0;
        int max_dis=INT_MIN;
        while(r<nums.size()-1){
            for(int i=l;i<=r;i++){
                max_dis=max(max_dis,i+nums[i]);
            }
            l=r+1;
            r=max_dis;
            jumps++;
        }
        return jumps;
    }
};