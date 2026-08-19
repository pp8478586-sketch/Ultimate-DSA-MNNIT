/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
    
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>mp;
        Node*temp=head;
        Node*newHead=NULL;
        while(temp){
            int data= temp->val;
            Node*newNode=new Node(data);
            mp[temp]=newNode;
            temp=temp->next;
        }
        temp=head;
        while(temp){
            Node*copyNode=mp[temp];
            if(newHead==NULL){
                newHead=copyNode;
            }
           
                copyNode->next=mp[temp->next];
            
           
                copyNode->random=mp[temp->random];
            
            temp=temp->next;
        }
        return newHead;
    }
};