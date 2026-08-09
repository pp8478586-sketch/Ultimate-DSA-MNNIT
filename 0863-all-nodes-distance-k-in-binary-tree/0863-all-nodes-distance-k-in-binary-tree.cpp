/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
   

void markParents(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&parent_track){
    if(root==NULL)return ;
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode*curr=q.front();
        q.pop();
        if(curr->left){
            parent_track[curr->left]=curr;
            q.push(curr->left);
        }
        if(curr->right){
            parent_track[curr->right]=curr;
            q.push(curr->right);
        }
    }
}
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
   
    markParents(root,parent_track);
    queue<TreeNode*>q;
    unordered_map<TreeNode*,bool>visited;
    q.push(target);
    visited[target]=true;
    int curr_level=0;
    while(!q.empty()){
        if(curr_level++==k)break;
        int n=q.size();
        for(int i=0;i<n;i++){
            TreeNode*curr=q.front();
            q.pop();
            if(curr->left&&!visited[curr->left]){
                q.push(curr->left);
                visited[curr->left]=true;
            }
            if(curr->right&&!visited[curr->right]){
                q.push(curr->right);
                visited[curr->right]=true;
            }
            if(parent_track.find(curr)!=parent_track.end()&&!visited[parent_track[curr]]){
                q.push(parent_track[curr]);
                visited[parent_track[curr]]=true;
            }
        }

    }
    vector<int>ans;
    while(!q.empty()){
        TreeNode*node=q.front();
        q.pop();
        ans.push_back(node->val);
    }
    return ans;
    }
};