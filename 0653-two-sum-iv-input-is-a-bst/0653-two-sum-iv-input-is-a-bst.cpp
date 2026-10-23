/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    stack<TreeNode*>st1;
    stack<TreeNode*>st2;
    void helper(TreeNode*root){
        TreeNode*temp=root;
        while(temp){
            st1.push(temp);
            temp=temp->left;
        }
        temp=root;
        while(temp){
            st2.push(temp);
            temp=temp->right;
        }
    }
    int next(){
        TreeNode*curr=st1.top();
        int ans=curr->val;
        st1.pop();
        curr=curr->right;
        while(curr){
            st1.push(curr);
            curr=curr->left;
        }
        return ans;
    }
    int last(){
        TreeNode*curr=st2.top();
        int ans=curr->val;
        st2.pop();
        curr=curr->left;
        while(curr){
            st2.push(curr);
            curr=curr->right;
        }
        return ans;
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        helper(root);
        int first=next();
        int second=last();
        while(first<second){
            if(second==k-first)return true;
            else if(second<k-first){
                first=next();
            }
            else{
                second=last();
            }
        }
        return false;
        
        
        
    }
};