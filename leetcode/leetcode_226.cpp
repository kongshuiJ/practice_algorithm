//
// Created by kongshui on 5/18/21.
//

/*
 *      4
 *    /   \
 *   2     7
 *  / \   / \
 * 1   3 6   9
 *
 *      4
 *    /   \
 *   7     2
 *  / \   / \
 * 9   6 3   1
 *
 */

#include <iostream>

struct TreeNode
{
    int         val;
    TreeNode    *left;
    TreeNode    *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};

class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return root;

        TreeNode *tmp   = root->left;
        root->left      = root->right;
        root->right     = tmp;

        root->left      = invertTree(root->left);
        root->right     = invertTree(root->right);

        return root;
    }
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node6(6);
    TreeNode node7(7);
    TreeNode node9(9);

    node4.left   = &node2;
    node4.right  = &node7;

    node2.left   = &node1;
    node2.right  = &node3;

    node7.left  = &node6;
    node7.right  = &node9;

    Solution tmp;
    tmp.invertTree(&node4);

    return 0;
}