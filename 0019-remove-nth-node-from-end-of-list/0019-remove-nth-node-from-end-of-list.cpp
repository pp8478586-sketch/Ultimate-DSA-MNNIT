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
        if(head==NULL)return head;
        ListNode*temp=head;
        int total=0;
        while(temp!=nullptr){
            total++;
            temp=temp->next;
        }
        // cnt is the number of the node from the start to be deleted
        int target=total-n+1;
        if(target<1)return head;
        if(target==1){
            ListNode*newHead=head->next;
            delete head;
            return newHead;
        }
        temp=head;
        int cnt=0;
        ListNode*prev=NULL;
        while(temp!=NULL){
            cnt++;
            if(cnt==target){
                prev->next=temp->next;
                delete temp;
                break;
            }
            prev=temp;
            temp=temp->next;
        }
        return head;
    }

};