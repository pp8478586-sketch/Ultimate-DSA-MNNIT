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
    int helper(TreeNode*root,int &count,int k){
        if(root==NULL)return -1;
        int left= helper(root->left,count,k);
        if(left!=-1)return left;
        count ++;
        if(count==k){
            return root->val;
        }
        return helper(root->right,count,k);
        
        
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        return helper(root,count,k);
        
        
    }
};