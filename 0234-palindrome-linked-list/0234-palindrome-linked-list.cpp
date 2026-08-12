/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode*reverseLinkedList(ListNode*head){
        ListNode*curr=head;
        ListNode*prev=NULL;
        while(curr){
            ListNode*nextNode=curr->next;
            curr->next=prev;
            prev=curr;
            curr=nextNode;
        }
        return prev;
    }
public:

    bool isPalindrome(ListNode* head) {
        if(head==NULL)return false;
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast!=NULL&&fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        if(fast!=NULL){
            slow=slow->next;
        }
        ListNode*newSlow=reverseLinkedList(slow);
        ListNode*temp=newSlow;
        ListNode*second=head;
        while(temp){
            if(temp->val!=second->val){
                reverseLinkedList(newSlow);
                return false;
            }
            temp=temp->next;
            second=second->next;
        }
        reverseLinkedList(newSlow);
        return true;
    }

};