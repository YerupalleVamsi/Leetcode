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
        vector<vector<int>>res;
        if(!root)return res;
        queue<TreeNode*>q;
        q.push(root);
        bool z=true;
        while(!q.empty()){
            int qsize=q.size();
            vector<int>s(qsize);
            for(int i=0;i<qsize;i++){
                TreeNode* n=q.front();
                q.pop();
                int idx=z? i:(qsize-1-i);
                s[idx]=n->val;
                if(n->left)q.push(n->left);
                if(n->right)q.push(n->right);
            }
            res.push_back(s);
            z=!z;
        }
        return res;
    }
};