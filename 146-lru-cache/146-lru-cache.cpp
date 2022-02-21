class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
        
    };
    
    //************** LRU Data Members*******************
    Node* head;
    Node* tail;
    
    int capacity;
    unordered_map<int, Node*> mp;
    
    //***************************************************
    
    //Constructor
    LRUCache(int _capacity) {
        capacity = _capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void addNode(Node* newNode) {
        Node* temp = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = temp;
        temp->prev = newNode;
    }
        
    void deleteNode(Node* delNode) {
        Node* delprev = delNode->prev;
        Node* delnext = delNode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }
    
    //Get method to check for cache
    int get(int _key) {
        if(mp.find(_key) != mp.end()) {
            Node* resNode = mp[_key];
            int res = resNode->val;
            mp.erase(_key);
            deleteNode(resNode); //Remove from old position
            addNode(resNode); // To insert it at most recent position
            mp[_key] = head->next;
            return res;
        }
        return -1;
    }
    
    //Put method to insert current value to cache
    void put(int _key, int _val) {
        if(mp.find(_key) != mp.end()) {
            Node* existingNode = mp[_key];
            mp.erase(_key);
            deleteNode(existingNode);
        }
        else if(mp.size() == capacity) { //If size is full 
            mp.erase(tail->prev->key); //Eraase least recent key
            deleteNode(tail->prev); //delete Node which is least recent used
        }
        Node* newNode = new Node(_key, _val);
        addNode(newNode);
        mp[_key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */