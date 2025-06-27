class Solution {
public:
    bool isvalid(string& s,string& seq, int k) {
       int cnt=0,i=0;
       for(char c:s){
        if(c==seq[i])
        { i++;
            if(i==seq.size())
            {
                i=0;
                cnt++;
                if(cnt==k)return true;
            }
        }
       }
       return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> freqMap;
        for (char ch : s) {
            freqMap[ch]++;
        }

        vector<char> filtered; // the chars with freq atleast k that's what we need in ans nigga
        for (const auto& [ch, freq] : freqMap) {
            if (freq >= k) {
                filtered.push_back(ch);
            }
        }
        queue<string> q; // bfs to generate all possible combinations i tried dfs but ...  TLE!!!
        q.push("");
        string best = "";
        while (!q.empty()) {
        string curr = q.front(); q.pop();
        for (char ch : filtered) {
            string next = curr + ch;

            if (isvalid(s, next, k)) {
                if (next.size() > best.size() || (next.size() == best.size() && next > best)) {
                    best = next; // updating the best which is the lexicographically largest one
                }
                q.push(next); 
            }
        }
    }

    return best;
    }
};
