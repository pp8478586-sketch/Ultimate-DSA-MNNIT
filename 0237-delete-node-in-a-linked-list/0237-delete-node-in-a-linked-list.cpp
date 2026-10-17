/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node){
       int next_value=node->next->val;
       ListNode*temp=node;
       ListNode*prev=node;
       while(temp->next!=NULL){
            temp->val=next_value;
            prev=temp;
            temp=temp->next;
            if(temp->next)next_value=temp->next->val;
       }
       prev->next=NULL;
    }
};