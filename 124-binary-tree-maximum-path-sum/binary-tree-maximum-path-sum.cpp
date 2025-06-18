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
int Maxi=INT_MIN;
    int maxi(TreeNode* root){
        if(!root)return 0;
        int leftsum=max(maxi(root->left),0);
        int rightsum=max(maxi(root->right),0);
        int currsum=leftsum+rightsum+root->val;
        Maxi=max(Maxi,currsum);
        return root->val+max(leftsum,rightsum);


    }
    int maxPathSum(TreeNode* root) {
        maxi(root);
        return Maxi;
    }
};