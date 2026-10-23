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
    bool helper(TreeNode*root,int k,unordered_map<int,bool>&mp){
        if(root==NULL)return false;
        if (mp.find(k - root->val) != mp.end())return true;
        mp[root->val]=true;
        bool left=helper(root->left,k,mp);
        if(left)return true;
        return helper(root->right,k,mp);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_map<int,bool>mp;
        return helper(root,k,mp);
        
        
    }
};