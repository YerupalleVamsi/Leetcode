class Solution {
public:
    bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}
    void backtrack(vector<vector<string>>&res,vector<string> curr,string s,int currindex){
        if(currindex==s.size())
        {res.push_back(curr);
        return;}
        for(int i=currindex;i<s.size();i++){
            if(isPalindrome(s,currindex,i)){
                curr.push_back(s.substr(currindex,i-currindex+1));
                backtrack(res,curr,s,i+1);
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        backtrack(res,{},s,0);
        return res;
    }
};