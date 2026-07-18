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
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL||n<1)return head;
        int cnt=1;
        ListNode*fast=head;
        while(fast->next!=NULL){
            if(cnt==n){
                break;
            }
            cnt++;
            fast=fast->next;
        }
        if(cnt<n)return head;
        ListNode*slow=head;
        ListNode*prev=nullptr;
        while(fast->next!=NULL){
            fast=fast->next;
            prev=slow;
            slow=slow->next;
        }
        if(slow==head){
            ListNode*newHead=slow->next;
            delete head;
            return newHead;
        }
        prev->next=slow->next;
        delete slow;
        return head;
    }
};