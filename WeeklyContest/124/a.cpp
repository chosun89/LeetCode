#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define pb push_back
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        // node -> <height, parent of node>
        unordered_map<int, pair<int, int>> mp;
        
        int k = 0;
        while(!q.empty()) {
            int n = q.size();
            k++;
            for (int i = 0; i < n; i++) {
                TreeNode* top = q.front();
                if (top->left) {
                   q.push(top->left);   
                   mp[top->left->val] = {k, top->val};
                }
                if (top->right) {
                   q.push(top->right);
                   mp[top->right->val] = {k, top->val};
                }
                
                q.pop();
            }
        }
        
        if((mp[x].first == mp[y].first) && (mp[x].second != mp[y].second)) return true;
        else return false;
        
    }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->right= new TreeNode(4);
  root->right->right = new TreeNode(5);
  Solution s;
  cout << s.isCousins(root, 4,5) << endl;

}

