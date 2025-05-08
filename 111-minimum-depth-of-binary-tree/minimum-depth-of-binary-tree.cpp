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
    int helper(TreeNode* root,int depth){
        if(!root)
        return depth;
        else if(root->right && !(root->left)) return helper(root->right,depth+1);
        else if(root->left && !(root->right)) return helper(root->left,depth+1);
        return min(helper(root->left,depth+1),helper(root->right,depth+1));
    }
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int depth=helper(root,0);
        return depth;
    }
};