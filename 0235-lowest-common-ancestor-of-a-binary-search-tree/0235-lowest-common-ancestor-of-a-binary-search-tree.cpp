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
    TreeNode*helper(TreeNode*root,TreeNode*p,TreeNode*q){
        if(root==p||root==q||root==NULL)return root;
        TreeNode*left=helper(root->left,p,q);
        TreeNode*right=helper(root->right,p,q);
        if(left&&right)return root;
        return right?right:left;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL)return NULL;
            TreeNode*temp=root;
            while(temp!=NULL){
                if(temp->val<p->val&&temp->val<q->val){
                    temp=temp->right;
                }
                else if(temp->val>p->val&&temp->val>q->val){
                    temp=temp->left;  
                }
                else break;
            }
            return helper(temp,p,q);
    }
};