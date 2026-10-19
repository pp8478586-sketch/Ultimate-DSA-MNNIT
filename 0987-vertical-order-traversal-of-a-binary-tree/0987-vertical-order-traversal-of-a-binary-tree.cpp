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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        map<int,vector<int>>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            map<int,vector<int>>levelmap;
            for(int i=0;i<n;i++){
                TreeNode*curr=q.front().first;
                int level=q.front().second;
                q.pop();
                levelmap[level].push_back(curr->val);
                if(curr->left)q.push({curr->left,level-1});
                if(curr->right)q.push({curr->right,level+1});
            }
            for(auto &it:levelmap){
                sort(it.second.begin(),it.second.end());
                for(int x:it.second){
                    mp[it.first].push_back(x);
                }
                    
            }
        }
        
        for(auto x: mp){
            ans.push_back(x.second);
        }
        return ans;
        
    }
};