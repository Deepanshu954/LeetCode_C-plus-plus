class AllOne {
private:
    struct Node {
        int count;
        unordered_set<string> keys;
        Node* prev;
        Node* next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };
    
    unordered_map<string, Node*> keyNode;
    Node* head;
    Node* tail;
    
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    
public:
    AllOne() {
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
    }
    
    void inc(string key) {
        if (keyNode.find(key) == keyNode.end()) {
            if (head->next->count != 1) {
                Node* newNode = new Node(1);
                newNode->next = head->next;
                newNode->prev = head;
                head->next->prev = newNode;
                head->next = newNode;
            }
            head->next->keys.insert(key);
            keyNode[key] = head->next;
        } else {
            Node* curr = keyNode[key];
            int newCount = curr->count + 1;
            
            if (curr->next->count != newCount) {
                Node* newNode = new Node(newCount);
                newNode->next = curr->next;
                newNode->prev = curr;
                curr->next->prev = newNode;
                curr->next = newNode;
            }
            
            curr->next->keys.insert(key);
            keyNode[key] = curr->next;
            curr->keys.erase(key);
            
            if (curr->keys.empty()) {
                removeNode(curr);
            }
        }
    }
    
    void dec(string key) {
        Node* curr = keyNode[key];
        int newCount = curr->count - 1;
        
        if (newCount == 0) {
            keyNode.erase(key);
        } else {
            if (curr->prev->count != newCount) {
                Node* newNode = new Node(newCount);
                newNode->prev = curr->prev;
                newNode->next = curr;
                curr->prev->next = newNode;
                curr->prev = newNode;
            }
            curr->prev->keys.insert(key);
            keyNode[key] = curr->prev;
        }
        
        curr->keys.erase(key);
        if (curr->keys.empty()) {
            removeNode(curr);
        }
    }
    
    string getMaxKey() {
        if (tail->prev == head) return "";
        return *(tail->prev->keys.begin());
    }
    
    string getMinKey() {
        if (head->next == tail) return "";
        return *(head->next->keys.begin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */