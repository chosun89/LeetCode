#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    map<TreeNode *, int> depth;
    map<TreeNode *, TreeNode *> parent;

    void dfs(TreeNode *node, TreeNode *par) {
        if (node == nullptr)
            return;

        parent[node] = par;
        depth[node] = par == nullptr ? 0 : depth[par] + 1;
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

int main() {

}

