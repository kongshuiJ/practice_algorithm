//
// Created by kongshui on 5/17/21.
//

/*
 * 给你二叉树的根结点 root ，请你将它展开为一个单链表：
 * 展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
 * 展开后的单链表应该与二叉树 先序遍历 顺序相同。
 *
 * 提示：
 * 树中结点数在范围 [0, 2000] 内
 * -100 <= TreeNode.val <= 100
 *
 * 进阶：你可以使用原地算法（O(1) 额外空间）展开这棵树吗？
 *
 * 示例 1：
 * 输入：root = [1,2,5,3,4,null,6]
 * 输出：[1,null,2,null,3,null,4,null,5,null,6]
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 * 示例 3：
 * 输入：root = [0]
 * 输出：[0]
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
    void flatten(TreeNode *root)
    {
        if (root == nullptr)
            return;

        // 后序
        flatten(root->left);
        flatten(root->right);

        if(root->left != nullptr)
        {
            TreeNode *left  = root->left;

            TreeNode *cur = left;
            while (cur->right)
                cur = cur->right;

            cur->right  = root->right;
            root->left  = nullptr;
            root->right = left;
        }
    }
};

int main()
{
    TreeNode node1(1);
    TreeNode node2(2);
    TreeNode node3(3);
    TreeNode node4(4);
    TreeNode node5(5);
    TreeNode node6(6);

    node1.left   = &node2;
    node1.right  = &node5;

    node2.left   = &node3;
    node2.right  = &node4;

    node5.right  = &node6;

    Solution tmp;
    tmp.flatten(&node1);

    return 0;
}