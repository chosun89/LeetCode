#include <bits/stdc++.h>
#include "buildtree"
#define pb push_back
using namespace std;

class Solution {
public:
	int maxLevelSum(TreeNode* root) {
		queue<TreeNode* root> q;
		q.push(root);

    pair<int, int> maxi = { root->val, 1 };
    int height = 0;
		while(!q.empty()) {
      int n = q.size();
      int sum = 0;
      height++;
      for (int i = 0; i < n; i++) {
        TreeNode* top = q.front();
        sum += top->val;
        if (top->left) q.push(top->left);
        if (top->right) q.push(top->right);
        q.pop();
      }

      if (sum >= maxi.first && maxi.second < height) {
        maxi.first = sum;
        maxi.second = height;
      }

      return maxi.height;

	  }
};

int main() {

Solution s;
TreeNode* root = { 1,7,0,7,-8,null,null};
cout << s.maxLevel(root);

}

