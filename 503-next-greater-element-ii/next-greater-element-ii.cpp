class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int>s;
        int n=nums.size();
        vector<int>res(n,-1);
        for (int j=0;j<2*n;j++){
            int i=j%n;
            while (!s.empty() && nums[s.top()]<nums[i]){
                res[s.top()]=nums[i];
                s.pop();
            }
            if(j<n)
            s.push(i);
        }
     
        return res;
    }
};