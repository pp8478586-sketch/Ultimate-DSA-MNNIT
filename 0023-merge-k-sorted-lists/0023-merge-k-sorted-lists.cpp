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
        if(list1==NULL&&list2==NULL)return NULL;
        ListNode*temp1=list1;
        ListNode*temp2=list2;
        ListNode*head=new ListNode(1);
        ListNode*tail=head;
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
        ListNode*newHead=head->next;
        delete head;
        return newHead;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*>starts=lists;
        while(lists.size()>1){
            vector<ListNode*>newLists;
            for(int i=0;i<lists.size();i+=2){
                ListNode*first=lists[i];
                ListNode*second=(i+1<lists.size())?lists[i+1]:NULL;
                ListNode*merged=mergeTwoLists(first,second);
                newLists.push_back(merged);
            }
            lists=newLists;  
        }
        return lists.empty()?NULL:lists[0];
    }
};