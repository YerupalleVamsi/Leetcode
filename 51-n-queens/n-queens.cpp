class Solution {
public:
    bool magnus(int r,vector<string>&b,int c,int n){
        // lets store the r,c
        int R=r;
        int C=c;
        while(c>=0 && r>=0){
            if(b[r][c]=='Q')return false;
            r--;
            c--;
        } //upper diag

        r=R;
        c=C; // reset r,c

        while(c>=0){
            if(b[r][c]=='Q')return false;
            c--;
        }
        c=C;
        while(r<n && c>=0){
            if(b[r][c]=='Q')return false;
            r++;
            c--;
        }
        return true;
    }
    void backtrack(vector<string>&b,vector<vector<string>>&res,int n, int currcol){
        if(currcol==n){
            res.push_back(b);
            return;
        }

        // lets check 
        for(int r=0;r<n;r++){
            if(magnus(r,b,currcol,n)){
                b[r][currcol]='Q';
                backtrack(b,res,n,currcol+1);
                b[r][currcol]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>b(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            b[i]=s;
        } // making a high quality board so i can smash it like magnus
        backtrack(b,res,n,0);
        return res;
    }
};