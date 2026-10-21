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
    TreeNode*helper(vector<int>&preorder,vector<int>&inorder,int preStart,int inStart,int inEnd,unordered_map<int,int>&mp){
        if(inStart>inEnd)return NULL;
        TreeNode*newNode=new TreeNode(preorder[preStart]);
        int idx=mp[preorder[preStart]];
        newNode->left=helper(preorder,inorder,preStart+1,inStart,idx-1,mp);
        newNode->right=helper(preorder,inorder,preStart+idx-inStart+1,idx+1,inEnd,mp);
        return newNode;

    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return helper(preorder,inorder,0,0,n-1,mp);
        
        
    }
};