#ifndef BUILDTREE_H
#define BUILDTREE_H

#include <queue>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<string> split(string str, char delimiter) {
    istringstream iss(str);
    string token;
    vector<string> res;

    while (getline(iss, token, delimiter)) {
        res.push_back(token);
    }

    return res;
}

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

void pre_dfs(TreeNode* root) {
    if (!root) return;

    cout << root->val << endl;
    pre_dfs(root->left);
    pre_dfs(root->right);
}

void post_dfs(TreeNode* root) {
    if (!root) return;

    post_dfs(root->left);
    post_dfs(root->right);
    cout << root->val << endl;
}

void in_dfs(TreeNode* root) {
    if (!root) return;

    in_dfs(root->left);
    cout << root->val << endl;
    in_dfs(root->right);
}

#endif
