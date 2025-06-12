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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>ans;
        queue<TreeNode*>q;
        if(!root)return ans;
        q.push(root);
        while(!q.empty()){
            int value;
            int qsize=q.size();
            for(int i=0;i<qsize;i++){
                TreeNode* n=q.front();
                q.pop();
                value=n->val;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            ans.push_back(value);

        }
        return ans;
    }
};