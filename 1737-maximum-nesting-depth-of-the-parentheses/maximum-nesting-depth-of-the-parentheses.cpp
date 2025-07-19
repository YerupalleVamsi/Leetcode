class Solution {
public:
    int maxDepth(string s) {
        int max_d=0;
        int count=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                count++;
                max_d=max(max_d,count);
            }
            else if(s[i]==')'){
                count--;
            }
        }
        return max_d;
    }
};