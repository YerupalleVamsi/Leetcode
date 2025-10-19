class Solution {
public:
    void solve(string s,int a,int b,unordered_set<string>&res){
        if(res.count(s)) return ;
        else{
            res.insert(s);
        }
        string A = s;
        for(int i=0;i<s.size();i++){
            
            if(i%2==1){
                int curr = s[i]-'0';
                int next = (curr + a)%10;
                A[i] = next + '0';
            }
        }
        solve(A,a,b,res);
        int n = s.size();
        string B = s;
        rotate(B.begin(), B.end() - b, B.end());
        solve(B, a, b, res);

    }
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string>res;
        solve(s,a,b,res);
        string ans=s;
        for(string x:res){
            if(x<ans){
                ans=x;
            }
        }
        return ans;
    }
};