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
    int v;
    int d;
    void dfs(TreeNode* node,int curr_d){
        if(node==NULL) return ;
        if(curr_d==d-1){
            TreeNode* l = new TreeNode(v);
            TreeNode* r = new TreeNode(v);
            l->left=node->left;
            r->right=node->right;
            node->right = r;
            node->left = l;
            return ;
        }
            dfs(node->left,curr_d+1);
            dfs(node->right,curr_d+1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        d=depth;
        v=val;

        if(d==1){
            TreeNode* node = new TreeNode(val);
            node->left = root;
            return node;
        }
        dfs(root,1);
        return root;
    }
};