class LFUCache {
    class Node{
        public:
        int key;
        int value;
        int freq;
        Node*next;
        Node*prev;
        Node(int k,int v,int f){
            key=k;
            value=v;
            freq=f;
            next=NULL;
            prev=NULL;
        }
    };
    class dll{
        Node*head;
        Node*tail;
        public:
        void add(Node*node){
            node->next=head;
            node->prev=NULL;
            if(head){
                head->prev=node;
            }
            else{
                tail=node;
            }
            head=node;
        }
        void remove(Node*node){
            Node*prevNode=node->prev;
            Node*nextNode=node->next;
            if(prevNode){
                prevNode->next=nextNode;
            }
            else{
                head=nextNode;
            }
            if(nextNode){
                nextNode->prev=prevNode;
            }
            else{
                tail=prevNode;
            }
        }
        Node*getTail(){
            return tail;
        }
        bool isEmpty(){
            return head==NULL;
        }
    };
    unordered_map<int,Node*>keyMap;
    unordered_map<int,dll>freqMap;
    int miniFreq=0;
    int mainCounter=0;
    
public:
    LFUCache(int capacity) {
        mainCounter=capacity;
    }
    
    int get(int key) {
        int ans=-1;
        int f=0;
        if(keyMap.find(key)!=keyMap.end()){
            ans=keyMap[key]->value;
            f=keyMap[key]->freq;
            keyMap[key]->freq++;
            freqMap[f].remove(keyMap[key]);
            if(f==miniFreq&&freqMap[f].isEmpty()){
                miniFreq++;
            }
            freqMap[f+1].add(keyMap[key]);
        }
        return ans;
    }
    
    void put(int key, int value) {
        if(keyMap.find(key)!=keyMap.end()){
            int f=keyMap[key]->freq;
            keyMap[key]->freq++;
            keyMap[key]->value=value;
            freqMap[f].remove(keyMap[key]);
            freqMap[f+1].add(keyMap[key]);
            if(f==miniFreq&&freqMap[f].isEmpty()){
                miniFreq++;
            }
        }
        else{
            if(mainCounter==0)return;
            if(mainCounter==keyMap.size()){
                Node*deleteNode=freqMap[miniFreq].getTail();
                int keyVal=deleteNode->key;
                freqMap[miniFreq].remove(deleteNode);
                keyMap.erase(keyVal);
                delete deleteNode;
            }
            keyMap[key]=new Node(key,value,1);
            freqMap[1].add(keyMap[key]);
            miniFreq=1;
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */