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
    ListNode*mergeTwoLists(ListNode*list1,ListNode*list2){
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        ListNode*newHead=new ListNode(1);
        ListNode*tail=newHead;
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        while(temp1&&temp2){
            if(temp1->val<temp2->val){
                tail->next=temp1;
                tail=temp1;
                temp1=temp1->next;
            }
            else{
                tail->next=temp2;
                tail=temp2;
                temp2=temp2->next;
            }
        }
        if(temp1){
            tail->next=temp1;
        }
        if(temp2){
            tail->next=temp2;
        }
        ListNode*temp=newHead->next;
        delete newHead;
        return temp;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return NULL;
        if(head->next==NULL)return head;
        
        ListNode*slow=head;
        ListNode*fast=head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
           fast=fast->next->next;
           slow=slow->next; 
        }
        ListNode*temp=slow->next;
        if(slow)slow->next=NULL;
        ListNode*list1=sortList(head);
        ListNode*list2=sortList(temp);
        return mergeTwoLists(list1,list2);
    }
};