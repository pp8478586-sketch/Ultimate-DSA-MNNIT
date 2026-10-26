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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // using min heap 
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)pq.push({lists[i]->val,lists[i]});
        }
        ListNode*newHead=new ListNode(-1);
        ListNode*tail=newHead;
        while(!pq.empty()){
            ListNode*curr=pq.top().second;
            pq.pop();
            if(curr->next)pq.push({curr->next->val,curr->next});
            tail->next=curr;
            tail=curr;
        }
        return newHead->next;
    }
};