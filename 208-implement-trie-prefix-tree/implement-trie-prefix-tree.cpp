struct Node{
    Node *links[26];
    bool flag = false;
    bool has_key(char ch){
        return links[ch-'a']!=NULL;
    }
    void put(char ch,Node *node){
        links[ch-'a'] = node;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void set(){
        flag = true;
    }
    bool isend(){
        return flag;
    }
};
class Trie {
public:
    Node *root;
    Trie() {
        root = new  Node();
    }
    
    void insert(string word) {
        Node *node = root;
        for(char c:word){
            if(!node->has_key(c)){
                node->put(c,new Node());
            }
            node=node->get(c);
        } 
        node->set();
    }
    
    bool search(string word) {
        Node *node = root;
        for(char c:word){
            if(!node->has_key(c)){
                return false;
            }
            node=node->get(c);
        } 
        return node->isend();
    }
    
    bool startsWith(string prefix) {
        Node *node = root;
        for(char c:prefix){
            if(!node->has_key(c)){
                return false;
            }
            node=node->get(c);
        } 
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */