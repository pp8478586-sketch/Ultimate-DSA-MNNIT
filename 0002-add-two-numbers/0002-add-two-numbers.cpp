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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode*first=l1;
        ListNode*second=l2;
        int carry=0;
        ListNode*head=NULL;
        ListNode*prev=NULL;
        while(first!=NULL||second!=NULL||carry!=0){
            int a=0;
            int b=0;
            if(first){
                a=first->val;
            }
            if(second){
                b=second->val;
            }
            int sum=a+b+carry;
            int digit=sum%10;
            carry=sum/10;
            ListNode*newNode=new ListNode(digit);
            if(head==NULL){
                head=newNode;
                prev=newNode;
            }
            else{
                prev->next=newNode;
                prev=newNode;
            }
            if(first)first=first->next;
            if(second)second=second->next;
        }
        
        return head;

    }
};