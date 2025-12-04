class Solution {
public:
    int countCollisions(string directions) {
        int cnt=0;
        int l=0;
        int r=0;
        for(char c:directions){
            if(c!='S')cnt++;
        }
        for(char c:directions){
            if(c=='L')l++;
            else break;
        }
        for(int i=directions.size()-1;i>=0;i--){
            if(directions[i]=='R')r++;
            else break;
        }

        return cnt - r - l;
    }
};