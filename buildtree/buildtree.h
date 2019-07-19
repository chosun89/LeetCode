#ifndef BUILD_TREE_H
#define BUILD_TREE_H

#include "stringsplit.h"
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}

};

// builds a binary tree
// returns root*
TreeNode* buildTree(string str) {
    TreeNode* root;
    vector<string> tokens = split(str, ',');
    if (tokens.empty()) return root;

    int i = 0;
    queue<TreeNode*> q; 
    root = new TreeNode(stoi(tokens[0]));
    q.push(root);

    while(!q.empty()) {

        TreeNode* top = q.front();
        if(2*i + 1 < tokens.size() &&  tokens[2*i + 1] != "null") {
            TreeNode* left = new TreeNode(stoi(tokens[2*i+1]));
            top->left = left;
            q.push(left);
        }

        if(2*i + 2 < tokens.size() &&  tokens[2*i + 2] != "null") {
            TreeNode* right = new TreeNode(stoi(tokens[2*i+2]));
            top->right = right;
            q.push(right);
        }

        q.pop();
        i++;
    }

    return root;
}

void dfs(TreeNode* root) {
    if (!root) return;

    cout << root->val << endl;
    dfs(root->left);
    dfs(root->right);

}

#endif
