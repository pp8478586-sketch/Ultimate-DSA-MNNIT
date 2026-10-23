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
    void swap(TreeNode*first,TreeNode*second){
        int firstVal=first->val;
        int secondVal=second->val;
        first->val=secondVal;
        second->val=firstVal;
    }
    bool helper(TreeNode*root,TreeNode*mini,TreeNode* maxi){
        if(root==NULL)return false;
        if(maxi&&root->val>maxi->val){
            swap(root,maxi);
            return true;
        }
        else if(mini&&root->val<mini->val){
            swap(root,mini);
             return true;
        }
        if(helper(root->left,mini,root))return true;
        return helper(root->right,root,maxi);
        
    }
public:
    void recoverTree(TreeNode* root) {
        while(helper(root,NULL,NULL));
    }
};