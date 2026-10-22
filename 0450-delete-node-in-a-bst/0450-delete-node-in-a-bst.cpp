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
    TreeNode*subTree(TreeNode*root){
            if(root->left&&root->right){
                TreeNode*temp=root->left;
                while(temp->right){
                    temp=temp->right;
                }
                temp->right=root->right;
                return root->left;
            }
            else if(root->left){
                return root->left;
            }
            else if(root->right){
                return root->right;
            }
            else {
                return NULL;
            }
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        if(root->val==key){
            return subTree(root);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else {
            root->left=deleteNode(root->left,key);
        }
        return root;
    }
};