class Solution {
public:
    void rec(vector<vector<int>>&res,int curr_num,int n,int k,vector<int>curr){
        if(curr.size()==k){
            res.push_back(curr);
            return ;
        }
        if(curr_num > n) return;
        if (curr.size() + (n - curr_num + 1) < k) return;
        curr.push_back(curr_num);        
        rec(res,curr_num+1,n,k,curr);
        curr.pop_back();
        rec(res,curr_num+1,n,k,curr);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        rec(res,1,n,k,{});
        return res;
    }
};