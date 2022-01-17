#include <iostream>

struct treeNode
{
    int key;
    treeNode *lchild;
    treeNode *rchild;

    treeNode(int tempKey)
    {
        key = tempKey;
        lchild = nullptr;
        rchild = nullptr;
    }
};

int max_diameter = 0;

// 计算二叉树的最大深度
int maxDepth(treeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int left_max = maxDepth(root->lchild);
    int right_max = maxDepth(root->rchild);

    int cur_diameter = left_max + right_max;
    max_diameter = std::max(max_diameter, cur_diameter);

    return 1 + std::max(left_max, right_max);
}

int diameterOfBinaryTree(treeNode *root)
{
    maxDepth(root);
    return max_diameter;
}

int main()
{
    treeNode *root = new treeNode(9);
    treeNode *cur1 = new treeNode(1);
    treeNode *cur2 = new treeNode(2);
    treeNode *cur3 = new treeNode(3);
    treeNode *cur4 = new treeNode(4);
    treeNode *cur5 = new treeNode(5);

    root->rchild = cur1;
    cur1->lchild = cur2;
    cur1->rchild = cur3;

    cur2->lchild = cur4;
    cur2->rchild = cur5;

    printf("max diameter: %d\n", diameterOfBinaryTree(root));


    return 0;
}