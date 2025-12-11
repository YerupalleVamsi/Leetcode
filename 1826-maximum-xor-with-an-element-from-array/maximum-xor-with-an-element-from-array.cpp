struct Node{
    Node *links[2];
    bool haskey(int bit){
        return (links[bit]!=NULL);
    }
    Node *get(int bit){
        return links[bit];
    }
    void set(int bit,Node *node){
        links[bit] = node;
        return;
    }
};
class Trie{
    Node *root;
    public:
    Trie(){
        root = new Node();
    }
    void insert(int num){
        Node *node = root;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(!node->haskey(bit)){
                node->set(bit,new Node());
            }
            node = node->get(bit);
        }
    }
    int findmax(int num){
        Node *node = root;
        int maxnum=0;
        for(int i=31;i>=0;i--){
            int bit = (num>>i)&1;
            if(node->haskey(1-bit)){
                maxnum|=(1<<i);
                node=node->get(1-bit);
            }
            else{
                node=node->get(bit);
            }
        }
        return maxnum;
    }
};
class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(),nums.end());
        int n = queries.size();
        vector<pair<int,pair<int,int>>>oq;
        for(int i=0;i<n;i++){
            oq.push_back({queries[i][1],{queries[i][0],i}});
        }
        sort(oq.begin(),oq.end());
        vector<int>res(n,0);
        int idx=0;
        Trie t;
        for(int i=0;i<n;i++){
            int m = oq[i].first;
            int x = oq[i].second.first;
            int qi= oq[i].second.second;
            while(idx<nums.size() && nums[idx]<=m){
                t.insert(nums[idx]);
                idx++;
            }
            if(idx == 0) res[qi]=-1;
            else res[qi] = t.findmax(x);
        }
        return res;

    }
};