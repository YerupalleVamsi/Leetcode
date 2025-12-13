class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_set<string>s = {"electronics", "grocery", "pharmacy", "restaurant"};
        vector<pair<string,string>> cb;
        for(int i=0;i<code.size();i++){
            string curr_code = code[i];
            string curr_business = businessLine[i];
            bool isvalid = true;
            for(auto it:curr_code){
                if(!isalnum(it) && it!='_') {
                    isvalid = false;
                    break;
                }
            }
            if(curr_code.size()==0) isvalid=false;
            if(isActive[i] && s.count(curr_business) && isvalid ){
                cb.push_back({curr_business,curr_code});
            }
        }
        vector<string>res;
        sort(cb.begin(),cb.end());
        for(auto it: cb){
            res.push_back(it.second);
        }
        return res;
    }
};