class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n=numerator;
        long long d=denominator;
        if(n==0) return "0";
        bool isneg = false;
        if( n < 0 || d < 0 ) isneg=true;
        if(n<0 && d<0) isneg=false;
        if(n==d){
            return "1";
        }
        n=abs(n);
        d=abs(d);
        unordered_map<long long ,long long > seen;
        string res="";
        long long intpart= n/d;
        res=res+to_string(intpart);
        long long rem = n%d;
        int lastseen=-1;
        string dec="";
        int pos=0;
        while(rem!=0){
            if(seen.find(rem)!=seen.end()){
                dec.insert(seen[rem],"(");
                dec=dec+')';
                break;
            }
            seen[rem]=pos;
            rem*=10;
            int q = rem / d;
            dec=dec+to_string(q);
            rem=rem%d;
            pos++;
        }
        // cout << intpart << endl;
        // cout << dec<< endl;
        if(dec.size()==0){
            return (isneg)? "-"+res : res;
        }
        return (isneg)? "-"+res+"."+dec : res+"."+dec;
    }
};