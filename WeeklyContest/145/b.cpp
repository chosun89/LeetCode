class Solution {
public:
    map<TreeNode *, int> depth;
    map<TreeNode *, TreeNode *> parent;
    int deepest;

    void dfs(TreeNode *node, TreeNode *par) {
        if (node == nullptr)
            return;

        parent[node] = par;
        depth[node] = par == nullptr ? 0 : depth[par] + 1;
        deepest = max(deepest, depth[node]);
        dfs(node->left, node);
        dfs(node->right, node);
    }

    TreeNode *lca(TreeNode *a, TreeNode *b) {
        while (a != b) {
            if (depth[a] < depth[b])
                swap(a, b);

            a = parent[a];
        }

        return a;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth.clear();
        parent.clear();
        deepest = 0;
        dfs(root, nullptr);
        vector<TreeNode *> leaves;

        for (pair<TreeNode *, int> p : depth)
            if (p.second == deepest)
                leaves.push_back(p.first);

        TreeNode *answer = leaves[0];

        for (int i = 1; i < (int) leaves.size(); i++)
            answer = lca(answer, leaves[i]);

        return answer;
    }
};
