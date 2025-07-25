class Solution {
public:
    int minFlips(string s) {
        int n=s.size();
        int c0=0;
        int c1=0;
        int min_cost=INT_MAX;
        for(int i=0;i<2*n;i++){
            char curr=s[i%n];
            char s0=i%2 == 0? '0':'1';
            char s1=i%2 == 0? '1':'0';
            if(s0!=curr) c0++;
            if(s1!=curr) c1++;
            if(i>=n){
                int start=i-n; // we can get the start of the window man
                char winstart0= start %2 == 0? '0' : '1';
                char winstart1= start%2 == 0? '1' : '0';
                if(s[start]!=winstart0) c0--;
                if(s[start]!=winstart1) c1--;
                min_cost=min({c0,c1,min_cost});
            }
           
        }
        return min_cost;
    }
};