class Solution {
public:
    int maxDistance(string s, int k) {
        int x = 0, y = 0;
        int res=1;
        for (int i=0;i<s.size();i++) {
            if (s[i] == 'N') x++;
            else if (s[i] == 'S') x--;
            else if (s[i] == 'E') y++;
            else if (s[i] == 'W') y--;
            res=max(res,min(abs(x)+abs(y)+2*k,i+1));
        }
        return res;
        
       
    }
};
