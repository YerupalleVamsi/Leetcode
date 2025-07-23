class Solution {
public:
    void helper(string &s,int first,int second,int score,int &cnt){
        stack<char>st;
        for(char ch:s)
        {
            if(!st.empty() && st.top()==first && ch == second){
                cnt+=score;
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
        s="";
        while(!st.empty()){
            s+=st.top();
            st.pop();
        }
        reverse(s.begin(),s.end());
    }
    int maximumGain(string s, int x, int y) {
        int cnt=0;
        if(x>y){
            helper(s,'a','b',x,cnt);
            helper(s,'b','a',y,cnt);
            return cnt;
        }
        else{
            helper(s,'b','a',y,cnt);
            helper(s,'a','b',x,cnt);
            return cnt;
        }
    }
};