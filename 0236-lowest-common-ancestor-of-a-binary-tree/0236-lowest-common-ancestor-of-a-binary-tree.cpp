/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool helper(TreeNode*root,TreeNode*p,TreeNode*q,TreeNode*&ans){
        if(root==NULL)return false;
        bool leftSide=helper(root->left,p,q,ans);
        bool rightSide=helper(root->right,p,q,ans);
        if(leftSide&&rightSide&&ans==NULL){
            ans=root;
        }
        else if(leftSide==true&&(root==p||root==q)&&ans==NULL){
            ans=root;
        }
        else if(rightSide==true&&(root==p||root==q)&&ans==NULL){
            ans=root;
        }
        if(leftSide||rightSide||root==p||root==q)return true;
        return false;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode*ans=NULL;
        helper(root,p,q,ans);
        return ans;
        
    }
};