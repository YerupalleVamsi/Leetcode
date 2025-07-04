class Solution {
public:
    bool isValid(string s) {
     stack<char>st;
     for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(s[i]);
        }
        if(!st.empty() && s[i]==')' && st.top()=='('){
            st.pop();
        }
        else if(i>0 &&  s[i]==')' && st.empty())return false;
     }
     return st.empty();
    }

    void backtrack(vector<string>&res,int n,string curr){
        if(curr.size()>n)return;
        if(curr.size()==n && isValid(curr)){
            res.push_back(curr);
            return;
        }
        backtrack(res,n,curr+'(');
        backtrack(res,n,curr+')');
        return;
    }
    vector<string> generateParenthesis(int n) {
        // first we start with "(" we dont have an other option
        vector<string>res;
        backtrack(res,2*n,"(");
        return res;

    }
}; // yo wtf 5% aa shit 1hr bokka