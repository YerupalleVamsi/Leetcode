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
    void backtrack(vector<vector<int>>&res,TreeNode* root,int targetsum,vector<int>curr){
        if(!root)return;
        curr.push_back(root->val);
        targetsum-=root->val;
        if(targetsum==0 && !root->left && !root->right){
            res.push_back(curr);
        }
        backtrack(res,root->left,targetsum,curr);
        backtrack(res,root->right,targetsum,curr);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>res;
        vector<int>curr;
        backtrack(res,root,targetSum,curr);    
        return res;
        }
};