class Solution {
public:
    class dsu{
        public: 
        unordered_map<string,string>mpp;
        string find(string x){
            if(!mpp.count(x)) return x;
            return mpp[x] = find(mpp[x]);
        }
        void uni(string x,string y){
            string px = find(x);
            string py = find(y);
            if(px != py){
                mpp[px] = py;
            }
        }
    };
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        dsu d;
        unordered_map<string,string> emailToName;
        unordered_set<string> allEmails;
        for(auto &acc : accounts){
            string name = acc[0];
            string firstEmail = acc[1];
            emailToName[firstEmail] = name;
            allEmails.insert(firstEmail);
            for(int j = 2; j < acc.size(); j++){
                string email = acc[j];
                emailToName[email] = name;
                allEmails.insert(email);
                d.uni(firstEmail, email);
            }
        }
        unordered_map<string, vector<string>> groups;
        for(auto &email : allEmails){
            string root = d.find(email);
            groups[root].push_back(email);
        }
        vector<vector<string>> res;
        for(auto &g : groups){
            vector<string> emails = g.second;
            sort(emails.begin(), emails.end());

            string name = emailToName[emails[0]];
            emails.insert(emails.begin(), name);
            res.push_back(emails);
        }

        return res;
    }
};