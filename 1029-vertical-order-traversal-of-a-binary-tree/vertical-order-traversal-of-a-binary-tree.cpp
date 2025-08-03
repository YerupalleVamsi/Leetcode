class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // vertical -> level -> multiset of node values
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> q; // {node, {vertical, level}}

        q.push({root, {0, 0}});

        while (!q.empty()) {
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int vertical = p.second.first;
            int level = p.second.second;

            nodes[vertical][level].insert(node->val);

            if (node->left) {
                q.push({node->left, {vertical - 1, level + 1}});
            }
            if (node->right) {
                q.push({node->right, {vertical + 1, level + 1}});
            }
        }

        vector<vector<int>> res;

        for (auto& [vertical, level_map] : nodes) {
            vector<int> col;
            for (auto& [level, vals] : level_map) {
                col.insert(col.end(), vals.begin(), vals.end());
            }
            res.push_back(col);
        }

        return res;
    }
};
