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
        while(first!=NULL&&second!=NULL){
            int sum=first->val+second->val+carry;
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
            first=first->next;
            second=second->next;
        }
        if(first!=NULL){
            while(first!=NULL){
                int sum=first->val+carry;
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
                first=first->next;
            }  
        }
        if(second!=NULL){
            while(second!=NULL){
                int sum=second->val+carry;
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
                second=second->next;
            }
        }
        if(carry!=0){
            prev->next=new ListNode(carry);
        }
        return head;

    }
};