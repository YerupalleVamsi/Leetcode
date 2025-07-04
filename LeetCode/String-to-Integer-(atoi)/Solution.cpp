class Solution {
public:
    int myAtoi(string s) {
        vector<char>num;
        int n=s.size();
        // remove whitespace egoist
        int i=0;
        while(i<n&&(s[i]==' ')){
            i++;
        }
        // check sign + or - and move iterator to next bruh
        bool neg=false;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            neg = (s[i]=='-')?true:false;
            i++;
        }
        // we have to take only digits remember
        while(i<n && isdigit(s[i])){
            num.push_back(s[i]);
            i++;
        }

        // now store the res
        long long res=0;
        for(char ch:num){
            res=res*10+(ch-'0');
            if(!neg && res>INT_MAX) return INT_MAX;
            if(neg && -res<INT_MIN) return INT_MIN;
        }
        if(neg) res=-res;
        return (int)res;



    }
};