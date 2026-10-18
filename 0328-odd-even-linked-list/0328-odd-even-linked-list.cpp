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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL)return head;
        ListNode*temp=head->next->next;
        ListNode*oddHead=head;
        ListNode*evenHead=NULL;
        ListNode*even=NULL;
        evenHead=head->next;
        oddHead->next=NULL;
        even=evenHead;
        evenHead->next=NULL;
        ListNode*odd=oddHead;
        int count=3;
        while(temp){
            ListNode*newNode=temp->next;
            temp->next=NULL;
            if(count%2==1){
                odd->next=temp;
                odd=temp;
                temp=newNode;
            }
            else{
                temp->next=NULL;
                even->next=temp;
                even=temp;
                temp=newNode;
            }
            count++;
        }
        odd->next=evenHead;
        return oddHead;

        

    }
};