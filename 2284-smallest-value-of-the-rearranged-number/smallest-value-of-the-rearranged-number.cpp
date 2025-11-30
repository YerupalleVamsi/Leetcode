class Solution {
public:
    long long smallestNumber(long long num) {
        bool isneg = num<0;
        if(isneg) num=-num;
        string s = to_string(num);
        int zeros = 0;
        string res="";
        if(isneg){
            sort(s.begin(),s.end());
            reverse(s.begin(),s.end());
            long long r = stoll(s);
            return -r;
        }

        for(char c:s){
            if(c=='0') zeros++;
        }
        char first;
        sort(s.begin(),s.end());
        for(char c:s){
            if(c!='0'){
                first = c;
                break;
            }
        }
        int f = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]!='0' && f!=0)res = res+s[i];
            else if(s[i]==first){
                f++;
            }
        }
        sort(res.begin(),res.end());
        string z(zeros,'0');
        string ans= first+z+res;
        return  stoll(ans);
    }
};