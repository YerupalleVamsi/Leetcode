class Solution {
public:
    bool rec(string res){
        if(res.size()<2) return false;
        if(res.size()==2){
            if(res[0]==res.back())return true;
            else
            return false;
        }
        string next="";
        for(int i=1;i<res.size();i++){
             int a = res[i - 1] - '0';
            int b = res[i] - '0';
            int curr_num = (a + b) % 10;
            next += to_string(curr_num);
        }
        return rec(next);
    }
    bool hasSameDigits(string s) {
       return rec(s); 
    }
};