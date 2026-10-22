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
    TreeNode*helper(vector<int>&preorder,int &i,long long mini, long long maxi){
        if(i==preorder.size())return NULL;
        int value=preorder[i];
        if(value<mini||value>maxi)return NULL;
        TreeNode*newNode=new TreeNode(value);
        i++;
        newNode->left=helper(preorder,i,mini,value);
        newNode->right=helper(preorder,i,value,maxi);
        return newNode;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return helper(preorder,i,LLONG_MIN,LLONG_MAX);
    }
};