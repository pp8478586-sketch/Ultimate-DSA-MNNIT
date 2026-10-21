/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)return "N";
        return to_string(root->val)+","+
                serialize(root->left)+","+
                serialize(root->right);
        
    }
    TreeNode*helper(string &data,int &i){
        int start=i;
        while(i<data.size()&&data[i]!=','){
            i++;
        }
        string token=data.substr(start,i-start);
        if(i<data.size())i++;
        if(token=="N")return NULL;
        int value=stoi(token);
        TreeNode*newNode=new TreeNode(value);
        newNode->left=helper(data,i);
        newNode->right=helper(data,i);
        return newNode;

    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i=0;
        return helper(data,i);
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));