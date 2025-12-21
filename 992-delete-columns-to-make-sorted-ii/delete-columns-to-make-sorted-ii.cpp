class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n=strs.size();
        int m=strs[0].size();
        int cnt=0;
        vector<string>res(n,string(""));
        for(int c=0;c<m;c++){
            bool sorted=true;
            for(int r=0;r<n-1;r++){
                if(res[r]+strs[r][c] > res[r+1]+strs[r+1][c]){
                    sorted=false;
                    break;
                }
            }
            if(sorted){
                for(int i=0;i<n;i++){
                    res[i]+=strs[i][c];
                }
            }
            else{
                cnt++;
            }
        }
        return cnt;
    }
};