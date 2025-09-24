class LRUCache {
public:
    struct Node{
        int key,val;
        Node * next;
        Node * prev;
        Node () : key (0), val(0) , next(NULL) , prev(NULL){}
        Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
    };

    unordered_map<int,Node*> mpp;
    int c;
    Node * head = new Node(); 
    Node * tail = new Node(); 

    LRUCache(int capacity) {
        c = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    void remove(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertFront(Node* node){
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

    int get(int key) {
        if(mpp.find(key)!=mpp.end()){
            Node * res = mpp[key];
            remove(res);
            insertFront(res);
            return res->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)!=mpp.end()){
            Node* existing = mpp[key];
            existing->val = value;
            remove(existing);
            insertFront(existing);
            return;
        }
        if(mpp.size() == c){
            Node* lru = tail->prev;
            remove(lru);
            mpp.erase(lru->key);
            delete lru;
        }
        Node * cache = new Node(key,value);
        mpp[key] = cache;
        insertFront(cache);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */