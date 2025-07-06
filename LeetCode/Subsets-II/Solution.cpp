// class Solution {
//public:
//    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//        set<vector<int>>res;
//        sort(nums.begin(),nums.end());
//        int n=nums.size();
//        for(int num=0;num<(1<<n);num++){
//            vector<int>sub;
//            for(int i=0;i<n;i++){
//                if((num&(1<<i))>0){
//                    sub.push_back(nums[i]);
//                }
//            }
//            res.insert(sub);
//        }
//        vector<vector<int>>ans;
//        for(auto&s:res){
//            vector<int>temp(s.begin(),s.end());
//            ans.push_back(temp);
//        }
//        return ans;
//    }
// };
// 

//using set

class Solution {
public: // using backtracking and for loop
    void rec(vector<int>&nums,int index,vector<int>curr,vector<vector<int>>&res){
        res.push_back(curr);
        for(int i=index;i<nums.size();i++){
            if(i>index && nums[i]==nums[i-1])continue;
            curr.push_back(nums[i]);
            rec(nums,i+1,curr,res);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>Res;
        rec(nums,0,{},Res);
        return Res;
    }
};