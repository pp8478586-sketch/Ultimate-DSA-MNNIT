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
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL)return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        long long maxWidth=INT_MIN;
        while(!q.empty()){
            long long n=q.size();
            long long left=q.front().second;
            long long right=0;
            for(long long j=0;j<n;j++){
                TreeNode*curr=q.front().first;
                long long i=q.front().second-left;
                q.pop();
                if(right<i){
                    right=i;
                }
                if(curr->left)q.push({curr->left,2*i});
                if(curr->right)q.push({curr->right,2*i+1});
            }
            if(maxWidth<right+1){
                maxWidth=right+1;
            }
            
        }
        return maxWidth;
        
    }
};