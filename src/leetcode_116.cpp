//
// Created by kongshui on 5/17/21.
//

/*
 * 输入：root = [1,2,3,4,5,6,7]
 * 输出：[1,#,2,3,#,4,5,6,7,#]
 * 解释：给定二叉树如图 A 所示，你的函数应该填充它的每个 next 指针，
 * 以指向其下一个右侧节点，如图 B 所示。序列化的输出按层序遍历排列，同一层节点由 next 指针连接，'#' 标志着每一层的结束。
 *
 */

#include <iostream>

class Node
{
public:
    int     val;
    Node    *left;
    Node    *right;
    Node    *next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr)
    {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr)
    {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next)
    {}
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
            return root;

        if ((root->left != nullptr) && (root->right != nullptr))
        {
            root->left->next = root->right;
            if ((root->left->right != nullptr) && (root->right->left != nullptr))
                root->left->right->next = root->right->left;

            if (root->right->next)
            {
                if ((root->right->next->left != nullptr) && (root->right->right != nullptr))
                    root->right->right->next = root->right->next->left;
            }
        }

        root->left  = connect(root->left);
        root->right = connect(root->right);

        return root;
    }
};

int main()
{
    // [-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13]
    Node node_1(-1);
    Node node0(0);
    Node node1(1);
    Node node2(2);
    Node node3(3);
    Node node4(4);
    Node node5(5);
    Node node6(6);
    Node node7(7);
    Node node8(8);
    Node node9(9);
    Node node10(10);
    Node node11(11);
    Node node12(12);
    Node node13(13);

    node_1.left  = &node0;
    node_1.right = &node1;

    node0.left   = &node2;
    node0.right  = &node3;

    node1.left   = &node4;
    node1.right  = &node5;

    node2.left   = &node6;
    node2.right  = &node7;

    node3.left   = &node8;
    node3.right  = &node9;

    node4.left   = &node10;
    node4.right  = &node11;

    node5.left   = &node12;
    node5.right  = &node13;

    Solution tmp;
    Node *result = tmp.connect(&node_1);

#define print(node) { \
    printf("root:%d, left:%d, right:%d, next:%d\n", \
               node->val,                           \
               node->left != nullptr ? node->left->val : 0, \
               node->right != nullptr ? node->right->val : 0, \
               node->next != nullptr ? node->next->val : 0);\
               }

    if (result)
    {
        // root 1
        print(result);
        print(result->left);
        print(result->right);

        // left 2
        Node *cur = result->left;
        print(cur->left);
        print(cur->right);

        // right 3
        cur = result->right;
        print(cur->left);
        print(cur->right);
    }

    return 0;
}