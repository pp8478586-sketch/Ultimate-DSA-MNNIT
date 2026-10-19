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
    int lengthOfBinaryTree(TreeNode*root,int &ans){
        if(root==NULL)return 0;
        int leftHeight=lengthOfBinaryTree(root->left,ans);
        int rightHeight=lengthOfBinaryTree(root->right,ans);
        if(ans<leftHeight+rightHeight){
            ans=leftHeight+rightHeight;
        }
        return 1+max(leftHeight,rightHeight);
        
    }
public:
    int diameterOfBinaryTree(TreeNode* root){
        int ans=0;
        lengthOfBinaryTree(root,ans);
        return ans;
    }
};