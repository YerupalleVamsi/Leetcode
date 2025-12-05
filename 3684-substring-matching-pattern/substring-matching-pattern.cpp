class Solution {
public:
    bool hasMatch(string s, string p) {
        int idx = p.find('*');
        string fir = p.substr(0, idx);
        string sec = p.substr(idx + 1);
        int f_idx = s.find(fir);
        int s_idx = s.rfind(sec);
        if(f_idx==-1 || s_idx==-1 || f_idx + fir.size() > s_idx) return false;
        return true;
    }
};