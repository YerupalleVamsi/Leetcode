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
    typedef long long ll;
    ll prev = LLONG_MIN;
    bool check=true;
    void inorder(TreeNode *root){
        if(!root) return;
        inorder(root->left);
        if(root->val>prev){
            prev=root->val;
        }
        else{
        check=false;
        return ;}
        inorder(root->right);
    }
    bool isValidBST(TreeNode* root) {
        inorder(root);
        return check;
    }
};