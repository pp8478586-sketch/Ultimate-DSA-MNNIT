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
        if(head==NULL)return NULL;
        if(n<1)return head;
        ListNode*temp=head;
        ListNode*first=head;
        int cnt=0;
        ListNode*prev=NULL;
        int length=1;
        while(temp->next!=NULL){
            if(cnt<n-1){
                
                cnt++;
            }
            else{
                prev=first;
                first=first->next;
                

            }
            length++;
            temp=temp->next;
        }
        if(length<n)return head;
        if(first==head){
            ListNode*newHead=head->next;
            delete head;
            return newHead;
        }
        else{
            prev->next=first->next;
            delete first;
            return head;
        }
    }
};