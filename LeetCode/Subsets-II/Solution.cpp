class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>res;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int num=0;num<(1<<n);num++){
            vector<int>sub;
            for(int i=0;i<n;i++){
                if((num&(1<<i))>0){
                    sub.push_back(nums[i]);
                }
            }
            res.insert(sub);
        }
        vector<vector<int>>ans;
        for(auto&s:res){
            vector<int>temp(s.begin(),s.end());
            ans.push_back(temp);
        }
        return ans;
    }
};