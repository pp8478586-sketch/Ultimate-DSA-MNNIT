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
    void helper(TreeNode*node,map<int,int>&mp,int level){
        if(node==NULL)return ;
        if(mp.find(level)==mp.end()){
            mp[level]=node->val;
        }
        if(node->right)helper(node->right,mp,level+1);
        if(node->left)helper(node->left,mp,level+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>mp;
        helper(root,mp,0);
        vector<int>ans;
        for(auto &it:mp){
            ans.push_back(it.second);
        }
        return ans;

    }
};