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
        stack<TreeNode*>st;
        int count=0;
        vector<vector<int>>ans;
        st.push(root);
        if(root==NULL)return ans;
        while(!st.empty()){
            vector<int>temp;
            int n=st.size();
            stack<TreeNode*>st2;
            for(int i=0;i<n;i++){
                TreeNode*curr=st.top();
                st.pop();
                temp.push_back(curr->val);
                if(count%2==1){
                    if(curr->right)st2.push(curr->right);
                    if(curr->left)st2.push(curr->left);
                }
                else{
                    if(curr->left)st2.push(curr->left);
                    if(curr->right)st2.push(curr->right);
                }
            }
            count++;
            ans.push_back(temp);
            st=st2;
        }
        return ans;
    }
};