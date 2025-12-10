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
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        int res=0;
        for(auto num:nums){
            t.insert(num);
        }
        for(auto num:nums){
            res=max(res,t.findmax(num));
        }
        return res;
    }
};