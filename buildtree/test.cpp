#include "buildtree.h"
#include <iostream>

int main() {
    auto res = split ( "hello,world,null", ',');
    for (auto s : res) cout << s << endl;
    cout << endl;

/* Example 1*/
    TreeNode* root = buildTree("1,2,3,4");
    cout << "1,2,3,4" << endl;
    /*
     *                          1
     *                         / \
     *                        2   3
     *                       /
     *                      4
     * */

    pre_dfs(root);
    cout << endl;

    in_dfs(root);
    cout << endl;

    post_dfs(root);
    cout << endl;

/* Example 2*/
    root = buildTree("1,null,2,null,3,null,4");
    cout << "1,null,2,null,3,null,4" << endl;
    /*
     *                         1
     *                          \
     *                           2
     *                            \
     *                             3
     *                              \
     *                               4
     * */

    pre_dfs(root);
    cout << endl;

    in_dfs(root);
    cout << endl;

    post_dfs(root);
    cout << endl;

/* Example 3*/
    root = buildTree("1,2,null,3,4");
    cout << "1,null,2,null,3,null,4" << endl;
    /*
     *                         1
     *                        / 
     *                       2    
     *                      / \
     *                     3   4
     * */

    pre_dfs(root);
    cout << endl;

    in_dfs(root);
    cout << endl;

    post_dfs(root);
    cout << endl;
}
