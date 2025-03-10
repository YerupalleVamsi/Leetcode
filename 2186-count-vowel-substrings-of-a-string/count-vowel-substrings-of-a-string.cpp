class Solution {
public:
    bool isVowel(char ch) {
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    
    int countVowelSubstrings(string word) {
        int count = 0;
        int n = word.size();
        
        for(int i = 0; i < n; i++) {
            if(!isVowel(word[i])) continue;
            
            unordered_map<char, int> vowels;
            vowels['a'] = 0;
            vowels['e'] = 0;
            vowels['i'] = 0;
            vowels['o'] = 0;
            vowels['u'] = 0;
            
            for(int j = i; j < n; j++) {
                if(!isVowel(word[j])) break;
                
                vowels[word[j]]++;
                
                bool allv = true;
                for(char v : {'a', 'e', 'i', 'o', 'u'}) {
                    if(vowels[v] == 0) {
                        allv = false;
                        break;
                    }
                }
                
                if(allv) count++;
            }
        }
        return count;
    }
};