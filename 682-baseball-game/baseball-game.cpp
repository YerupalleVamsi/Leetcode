class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>ans;
        for(string i:operations){
            if(i=="+"){
                int newrec=ans[ans.size()-1]+ans[ans.size()-2];
                ans.push_back(newrec);
            }
            else if(i=="C"){
                ans.pop_back();
            }
            else if(i=="D"){
                ans.push_back(ans[ans.size()-1]*2);
            }
           else {
                
                ans.push_back(stoi(i));
            }

        }
        int res=0;
        for(int num:ans){
            res+=num;
        }
        return res;
    }
};