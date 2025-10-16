class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>>q;
        q.push({beginWord,1});
        unordered_set<string>s(wordList.begin(),wordList.end());
        while(!q.empty()){
            auto [word,cnt] = q.front();
            q.pop();
            if(word == endWord) return cnt;
            for(int i=0;i<word.size();i++){
                char curr = word[i];
            for(char c='a';c<='z';c++){
                if(c == curr) continue;
                string temp = word;
                temp[i] = c;
                if(s.find(temp) != s.end()){
                    q.push({temp,cnt+1});
                    s.erase(temp);
                }
            }}
        }
        return 0;
    }
};