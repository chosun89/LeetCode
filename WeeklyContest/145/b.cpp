class Solution {
public:
    map <TreeNode*, TreeNode*> parent;
    map <TreeNode*, int> depth;
    int deepest;

    void dfs(TreeNode* root, TreeNode* prev) {
        if (!root) return;

        parent[root] = prev;
        depth[root] = prev == nullptr ? 0 : depth[prev] + 1;

        if (depth[root] > deepest)
            deepest = depth[root];

        dfs(root->left, root);
        dfs(root->right, root);
    }

    TreeNode* lca(TreeNode* a, TreeNode* b) {
        while (a != b) {
            if (depth[a] < depth[b])
                swap(a, b);

            a = parent[a];
        }
        return a;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {

        deepest = 0;
        dfs(root, nullptr);

        vector<TreeNode*> same_level;

        for (auto p : depth) {
            if (p.second == deepest)
                same_level.push_back(p.first)
        }

        TreeNode* res = same_level[0];
        for (int i = 1; i < same_level.size(); i++) {
            res = lca(res, same_level[i]);
        }

        return res;
    }
};
