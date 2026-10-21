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
    TreeNode*helper(vector<int>&preorder,vector<int>&inorder,int preStart,int preEnd,int inStart,int inEnd){
        if(inStart>inEnd)return NULL;
        TreeNode*newNode= new TreeNode(preorder[preStart]);
        int first=preorder[preStart];
        int i=inStart;
        while(inorder[i]!=first){
            i++;
        }
        newNode->left=helper(preorder,inorder,preStart+1,preStart+i-inStart,inStart,i-1);
        newNode->right=helper(preorder,inorder,preStart+i-inStart+1,preEnd,i+1,inEnd);
        return newNode;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode*head=new TreeNode(preorder[0]);
        return helper(preorder,inorder,0,preorder.size()-1,0,preorder.size()-1);
        
    }
};