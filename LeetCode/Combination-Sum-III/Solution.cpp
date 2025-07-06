class Solution {
public:
    void rec(int len,int target,vector<vector<int>>&res,vector<int>curr,int currnum,int currsum){
        if(target==currsum && curr.size()==len){
            res.push_back(curr);
            return;
        }
        for(int i=currnum;i<=9;i++){
            if(currsum+i>target)break;
            curr.push_back(i);
            rec(len,target,res,curr,i+1,currsum+i);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
       // base case
       vector<vector<int>>res;
       if(k>n)return  res;
       rec(k,n,res,{},1,0);
       return res;
    }
};