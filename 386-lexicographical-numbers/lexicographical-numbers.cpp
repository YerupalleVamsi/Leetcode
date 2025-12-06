class Solution {
public:
    void dfs(int curr,vector<int>&res,int n){
        if(curr>n)return;
        res.push_back(curr);
        for(int i=0;i<=9;i++){
            int newcurr=10*curr+i;
            if(newcurr<=n)
            dfs(newcurr,res,n);
        }
    }
    vector<int> lexicalOrder(int n) {
       vector<int>res;
       for(int i=1;i<10;i++){
        dfs(i,res,n);
       } 
       return res;
    }
};