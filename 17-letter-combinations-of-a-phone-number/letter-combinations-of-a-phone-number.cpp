class Solution {
public:

    /*void backtrack(string &digits,string curr,unordered_map<char,string>&mpp,int currindex,vector<string>&ans){
        if(curr.size()==digits.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=currindex;i<digits.size();i++){
                string next=mpp[digits[i]];
                for(char ch:next){
                    curr+=ch;
                backtrack(digits,curr,mpp,i+1,ans);
                curr.pop_back();}
        }
    }*/  // worked but unecessary nested loop
    void backtrack(string &digits,string curr,unordered_map<char,string>&mpp,int currindex,vector<string>&ans){
        if(curr.size()==digits.size()){
            ans.push_back(curr);
            return;
        }
        string next=mpp[digits[currindex]];  // removed the nested for loop
                for(char ch:next){
                    curr+=ch;
                backtrack(digits,curr,mpp,currindex+1,ans);
                curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        if(digits.size()==0)return ans;
        unordered_map<char,string> mpp={
            {'2',"abc"},
            {'3',"def"},
            {'4',"ghi"},
            {'5',"jkl"},
            {'6',"mno"},
            {'7',"pqrs"},
            {'8',"tuv"},
            {'9',"wxyz"}
        };
        backtrack(digits,"",mpp,0,ans);
        return ans;

    }
};