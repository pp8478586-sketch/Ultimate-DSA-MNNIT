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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*>q;
        int count=0;
        vector<vector<int>>ans;
        q.push(root);
        if(root==NULL)return ans;
        if(root==NULL)return ans;
        while(!q.empty()){
            int n=q.size();
            vector<int>temp(n);
            for(int i=0;i<n;i++){
                TreeNode*curr=q.front();
                q.pop();
                int idx=(count%2==0)?i:n-i-1;
                temp[idx]=curr->val;
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            count++;
            ans.push_back(temp);
        }
        return ans;
    }
};