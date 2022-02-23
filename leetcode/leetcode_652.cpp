//
// Created by kongshui on 5/19/21.
//

/*
 * 给定一棵二叉树，返回所有重复的子树。对于同一类的重复子树，你只需要返回其中任意一棵的根结点即可。
 *
 * 两棵树重复是指它们具有相同的结构以及相同的结点值。
 *
 * 示例 1：
 *
 *         1
 *        / \
 *       2   3
 *      /   / \
 *     4   2   4
 *        /
 *       4
 * 下面是两个重复的子树：
 *
 *       2
 *      /
 *     4
 * 和
 *
 *     4
 * 因此，你需要以列表的形式返回上述重复子树的根结点。
 */

#include <iostream>
#include <vector>
#include <map>

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
    std::vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        std::vector<TreeNode *> ans;
        if (root == nullptr)
            return ans;

        std::map<std::string, int> mp;
        dfs(root, ans, mp);

        return ans;
    }

private:

    std::string dfs(TreeNode *root, std::vector<TreeNode *> &ans, std::map<std::string, int> &mp)
    {
        if (root == nullptr)
            return " ";

        std::string tmp = std::to_string(root->val) + dfs(root->left, ans, mp) + dfs(root->right, ans, mp);

        if (mp[tmp] == 1)
            ans.push_back(root);

        mp[tmp]++;

        return tmp;
    }
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(2);
    TreeNode node6(4);
    TreeNode node7(4);

    node1.left   = &node2;
    node1.right  = &node3;

    node2.left   = &node4;
    node2.right  = &node5;

    node3.left   = &node5;
    node3.right  = &node6;

    node5.left   = &node7;

    Solution tmp;
    auto result = tmp.findDuplicateSubtrees(&node1);

    return 0;
}