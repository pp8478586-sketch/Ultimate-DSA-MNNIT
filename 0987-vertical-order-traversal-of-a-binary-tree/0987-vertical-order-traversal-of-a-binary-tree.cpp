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
    void helper(TreeNode*root,int col,int row,vector<tuple<int,int,int>>&nodes){
        if(root==NULL)return ;
        nodes.push_back({col,row,root->val});
        helper(root->left,col-1,row+1,nodes);
        helper(root->right,col+1,row+1,nodes);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>>nodes;
        vector<vector<int>>ans;
        helper(root,0,0,nodes);
        sort(nodes.begin(),nodes.end());
        int prev=INT_MIN;
        for(auto x:nodes){
            int col=get<0>(x);
            int val=get<2>(x);
            if(col!=prev){
                ans.push_back({});
                prev=col;
            }
            ans.back().push_back(val);
        }
        return ans;
        
        
    }
};