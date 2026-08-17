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
    ListNode*helperReverse(ListNode*head){
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*temp=head;
        ListNode*per=new ListNode(1);
        ListNode*tail=per;
        ListNode*tempHead=temp;
        while(temp){
           
            int cnt=1;
            while(cnt<k){
                if(temp->next){
                    temp=temp->next;
                    cnt++;
                }
                else {
                    break;
                } 
            }
            if(cnt==k){
                ListNode*newNode=temp->next;
                temp->next=NULL;
                ListNode*newHead=helperReverse(tempHead);
                tail->next=newHead;
                tail=tempHead;
                tempHead=newNode;
                temp=newNode;
            }
            else{
                tail->next=tempHead;
                break;
            }
    
        }
        return per->next;
    }
};