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
        Node*temp=head;
        Node*newHead=NULL;
        while(temp){
            Node*nextNode=temp->next;
            Node*copyNode=new Node(temp->val);
            temp->next=copyNode;
            copyNode->next=nextNode;
            temp=nextNode;
        }
        temp=head;
        while(temp){
            if(newHead==NULL){
                newHead=temp->next;
            }
            Node*copyNode=temp->next;
            
            if(temp->random)copyNode->random=temp->random->next;
            temp=temp->next->next;
        }
        // searate original list to copied list
        temp=head;
        while(temp){
            Node*newNode=temp->next;
            Node*originalNextNode=temp->next->next;
            Node*copyNextNode=NULL;
            if(originalNextNode)copyNextNode=originalNextNode->next;
            temp->next=originalNextNode;
            newNode->next=copyNextNode;
            temp=originalNextNode;
        }
        return newHead;


    }
};