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
    TreeNode*helper(vector<int>&preorder,vector<int>&inorder,int &preIndex,int inStart,int inEnd,unordered_map<int,int>&mp){
        if(inStart>inEnd)return NULL;
        TreeNode*newNode=new TreeNode(preorder[preIndex]);
        int idx=mp[preorder[preIndex++]];
        newNode->left=helper(preorder,inorder,preIndex,inStart,idx-1,mp);
        newNode->right=helper(preorder,inorder,preIndex,idx+1,inEnd,mp);
        return newNode;

    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int preIndex=0;
        return helper(preorder,inorder,preIndex,0,n-1,mp);
        
        
    }
};