class Solution {
public:
    string reversePrefix(string s, int k) {
        int N  = s.size();
        string f = s.substr(0,k);
        reverse(f.begin(),f.end());
        string n = s.substr(k);
        return f+n;
    }
};