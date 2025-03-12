class Solution {
public:
    void convert(unordered_set<string>&ans,string curr){
 map<char,string> m={{'a',".-"},{'b',"-..."},{'c',"-.-."},{'d',"-.."},{'e',"."},{'f',"..-."},{'g',"--."},{'h',"...."},{'i',".."},{'j',".---"},{'k',"-.-"},{'l',".-.."},{'m',"--"},{'n',"-."},{'o',"---"},{'p',".--."},{'q',"--.-"},{'r',".-."},{'s',"..."},{'t',"-"},{'u',"..-"},{'v',"...-"},{'w',".--"},{'x',"-..-"},{'y',"-.--"},{'z',"--.."}};
 string news="";
        for(int i=0;i<curr.size();i++){
            news+=m[curr[i]];
        }
        ans.insert(news);
    }
    int uniqueMorseRepresentations(vector<string>& words) {
 unordered_set<string>ans;
        for(int i=0;i<words.size();i++){
            convert(ans,words[i]);
        }
        return ans.size();

    }
};