class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>last_occurance;
        int start=0;
        int end=0;
        vector<int>p;
        for(int i=0;i<s.size();i++){
            last_occurance[s[i]]=i;
        }
        int farthest=-1;
        int left=0;
        for(int i=0;i<s.size();i++){
            farthest=max(farthest,last_occurance[s[i]]);
            if(i==farthest){
                p.push_back(farthest-left+1);
                left=i+1;
            }
        }
        return p;
    }
};