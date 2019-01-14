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
    vector<TreeNode*> allPossibleFBT(int N) {
      vector<TreeNode*> res;
      if (N == 0) return res;
      TreeNode* root = new TreeNode(0);
      recurse(res, N - 1, root, root);
      return res;
    }

    void recurse(vector<TreeNode*>& res, int N, TreeNode* root, TreeNode* curr) {
      if (N < 0) return;
      if (N == 0) {
        res.pb(root);
        return;
      }
      curr -> left = new TreeNode(0);
      curr -> right = new TreeNode(0);
      recurse(res, N - 2, root, curr->left);
      recurse(res, N - 2, root, curr->right);
    }
};

int main() {
  Solution s;
  s.allPossibleFBT(7);

}

