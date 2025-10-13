class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        int i=1;
        while(i<words.size()){
            string curr = words[i];
            string next = words[i-1];
            sort(curr.begin(),curr.end());
            sort(next.begin(),next.end());
            if(curr == next){
                words.erase(words.begin()+i);
            }
            else{
                i++;
            }
        }
        return words;
    }
};