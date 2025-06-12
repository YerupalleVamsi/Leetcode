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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        if(!root) return res;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            vector<int>store;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* n=q.front();
                q.pop();
                if(n->left!=NULL)q.push(n->left);
                if(n->right!=NULL)q.push(n->right);
                store.push_back(n->val);
            }
            res.push_back(store);
        }
        return res;
    }
};