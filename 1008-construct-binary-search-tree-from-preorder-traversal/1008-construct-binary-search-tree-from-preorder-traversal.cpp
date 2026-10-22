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
    TreeNode*helper(vector<int>&preorder,int start,int end){
        if(start>end)return NULL;
        TreeNode*newNode=new TreeNode(preorder[start]);
        int idx=start+1;
        while(idx<=end&&preorder[idx]<preorder[start]){
            idx++;
        }
        newNode->left=helper(preorder,start+1,idx-1);
        newNode->right=helper(preorder,idx,end);
        return newNode;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(preorder,0,preorder.size()-1);
    }
};