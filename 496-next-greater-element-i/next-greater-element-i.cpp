class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int,int>mpp;
        vector<int>res(nums1.size(),-1);
        for (int n:nums2){
            while (!s.empty() && s.top()<n){
                mpp[s.top()]=n;
                s.pop();
            }
            s.push(n);
        }
        for(int i=0;i<nums1.size();i++){
            if(mpp.find(nums1[i])!=mpp.end()){
                res[i]=mpp[nums1[i]];
            }
        }
        return res;
    }
};