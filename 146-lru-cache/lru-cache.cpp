class Node{
public:
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k,int v){
        key = k;
        val = v;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:

    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;
    int limit;

    void addNode(Node* newNode){
        Node* oldNext = head->next;
        head->next = newNode;
        newNode->next = oldNext;
        oldNext->prev = newNode;
        newNode->prev = head;
    }

    void delNode(Node* oldNode){
        Node* oldprev = oldNode->prev;
        Node* oldnext = oldNode->next;

        oldprev->next = oldnext;
        oldnext->prev = oldprev;
    }

    LRUCache(int capacity) {
        // yeh ek constructor hai

        limit = capacity;

        head = new Node(-1,-1);
        tail = new Node(-1,-1);

        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {

        if(mp.find(key) == mp.end()){
            return -1;
        }

        Node* ansNode = mp[key];
        int ans = mp[key]->val;

        delNode(ansNode);
        addNode(ansNode);

        return ans;
    }

    void put(int key, int value) {

        // agar key already exist karti hai
        if(mp.find(key) != mp.end()){

            Node* oldNode = mp[key];

            delNode(oldNode);
            mp.erase(key);

            delete oldNode;
        }

        // agar cache full ho gayi hai
        if(mp.size() == limit){

            Node* lru = tail->prev;

            mp.erase(lru->key);
            delNode(lru);

            delete lru;
        }

        Node* newNode = new Node(key,value);

        addNode(newNode);

        mp[key] = newNode;
    }
};
/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */