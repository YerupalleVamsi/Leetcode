class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())return ""; // base case
        string ans=strs[0]; // start string
        int len=ans.size(); // start size
        for(int i=1;i<strs.size();i++){
            string s=strs[i]; // check for everyother string
            while(len>s.size() || ans!=s.substr(0,len)){  // if the len > size of s [len--]
                                                            // or not equal then len--
                len--;
                if(len==0)return "";
                ans=ans.substr(0,len);                      // update ans
            }
            
        }
        return ans;
    }
};