class Solution {
public:
    string makeLower(string s) {
        string ans = "";
        for (char c : s) {
            ans += tolower(c);
        }
        return ans;
    }

    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string,int> mpp;
        unordered_map<string,string> C;
        unordered_map<string,string> v;

        for (int i = 0; i < wordlist.size(); i++) {
            string x = wordlist[i];
            string re = wordlist[i];
            mpp[x]++;
            if (C.find(makeLower(x)) == C.end())
                C[makeLower(x)] = x;
            for (int j = 0; j < x.size(); j++) {
                if (x[j]=='a'||x[j]=='e'||x[j]=='i'||x[j]=='o'||x[j]=='u')
                    x[j] = '#';
                else if (x[j]=='A'||x[j]=='E'||x[j]=='I'||x[j]=='O'||x[j]=='U')
                    x[j] = '#';
            }
            if (v.find(makeLower(x)) == v.end()) {   
                v[makeLower(x)] = re;
            }
        }

        vector<string> res;
        for (auto s : queries) {
            if (mpp.find(s) != mpp.end()) {
                res.push_back(s);
            }
            else if (C.find(makeLower(s)) != C.end()) {
                res.push_back(C[makeLower(s)]);  
            }
            else {
                string l= makeLower(s); 
                for (int j = 0; j < l.size(); j++) {
                    if (l[j]=='a'||l[j]=='e'||l[j]=='i'||l[j]=='o'||l[j]=='u')
                        l[j] = '#';
                }
                if (v.find(l) != v.end()) {
                    res.push_back(v[l]);
                } else {
                    res.push_back("");
                }
            }
        }
        return res;
    }
};
