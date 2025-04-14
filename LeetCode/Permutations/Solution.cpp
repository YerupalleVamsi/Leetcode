        vector<int>curr;
        int n=nums.size();
        vector<bool>vis(n,false);
       backtrack(res,nums,curr,vis,n);
        return res;    
    }
};