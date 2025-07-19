class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mpp;
        for(char ch:s){
            mpp[ch]++;
        }
        for(auto[ch,count] : mpp){
            pq.push({count,ch});
        }
        string res="";
        while(!pq.empty()){
            auto [count,ch] = pq.top();
            pq.pop();
            res+=string(count,ch);
        }
        return res;
    }
};
