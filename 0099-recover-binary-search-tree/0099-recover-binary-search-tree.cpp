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
    TreeNode*prev=NULL;
    TreeNode*first=NULL;
    TreeNode*second=NULL;
    void helper(TreeNode*root){
        if(root==NULL)return;
        helper(root->left);
        if(prev!=NULL&&root->val<prev->val){
            if(first==NULL)first=prev;
            second=root;
        }
        prev=root;
        helper(root->right);
    }
    
public:
    void recoverTree(TreeNode* root) {
        helper(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
    }
};