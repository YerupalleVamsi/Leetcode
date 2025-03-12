class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
 unordered_set<string>unq;
  vector<string> m = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
        for(int i=0;i<words.size();i++){
            string news="";
            for(char x : words[i]){
                news+=m[x-'a'];
            }
            unq.insert(news);
        }
        return unq.size();

    }
};