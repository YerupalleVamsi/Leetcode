class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
 unordered_set<string>unq;
  vector<string> m = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        for(string w:words){
            string news="";
            for(char x : w){
                news+=m[x-'a'];
            }
            unq.insert(news);
        }
        return unq.size();

    }
};