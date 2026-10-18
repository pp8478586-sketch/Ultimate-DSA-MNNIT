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
    int traversal(TreeNode*root,bool &balanced){
        if(root==NULL){
            return 0;
        }
        int leftHeight=traversal(root->left,balanced);
        int rightHeight=traversal(root->right,balanced);
        if(abs(leftHeight-rightHeight)>1){
            balanced=false;
        }
        return 1+max(leftHeight,rightHeight);
    }
    
    
public:
    bool isBalanced(TreeNode* root) {
        bool balanced=true;
        traversal(root,balanced);
        return balanced;
    }
};