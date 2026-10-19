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
    bool helper(TreeNode*a,TreeNode*b){
        if(a==NULL||b==NULL)return a==b;
        return a->val==b->val &&helper(a->left,b->right)&&helper(a->right,b->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return helper(root->left,root->right); 
    }
};