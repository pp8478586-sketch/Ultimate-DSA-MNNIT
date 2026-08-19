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
    ListNode* sortList(ListNode* head) {
        if(head==NULL)return NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        ListNode*temp=head;
        ListNode*newHead= new ListNode(1);
        ListNode*prev=newHead;
        while(temp){
            ListNode*nextNode=temp->next;
            pq.push({temp->val,temp});
            temp->next=NULL;
            temp=nextNode;
        }
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            prev->next=curr.second;
            prev=curr.second;
        }
        ListNode*ans=newHead->next;
        delete newHead;
        return ans;
    }
};