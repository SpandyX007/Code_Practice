class Node{
public:
    int key,val;
    Node* next;
    Node* prev;
    Node(int k, int v){
        key=k;
        val=v;
        next=nullptr;
        prev=nullptr;
    }
};

class LRUCache {
public:
    int limit;
    unordered_map<int,Node*> m;
    
    // implementation of DLL
    public:
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    

    void addNode(Node* newNode){
        Node* oldNext=head->next;
        head->next=newNode;
        oldNext->prev=newNode;
        newNode->next=oldNext;
        newNode->prev=head;
        return;
    }

    void deleteNode(Node* oldNode){
        Node* oldPrev=oldNode->prev;
        Node* oldNext=oldNode->next;

        oldPrev->next=oldNext;
        oldNext->prev=oldPrev;
    }


    LRUCache(int capacity) {
        limit=capacity;
        //stating initial case where head and tail are connected to each other
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        if(m.find(key)==m.end())
            return -1;
        Node* ansNode=m[key];
        int ans=ansNode->val;   

        //transposing the node to the front
        m.erase(key);
        deleteNode(ansNode);
        addNode(ansNode);
        m[key]=ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(m.find(key)!=m.end())
        {
            Node* oldNode=m[key];
            deleteNode(oldNode);
            m.erase(key);
        }
        if(m.size()==limit)
        {
            // delete LRU cache
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        Node* newNode=new Node(key, value);
        addNode(newNode);
        m[key]=newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */