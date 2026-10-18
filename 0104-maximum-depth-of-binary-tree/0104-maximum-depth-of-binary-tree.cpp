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
    void inorder(TreeNode*root,int depth,int &maxdepth){
        if(root==NULL)return;
        if(depth>maxdepth){
            maxdepth=depth;
        }
        inorder(root->left,depth+1,maxdepth);
        inorder(root->right,depth+1,maxdepth);
    }
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        int maxdepth=INT_MIN;
        inorder(root,1,maxdepth);
        return maxdepth;

        
    }
};