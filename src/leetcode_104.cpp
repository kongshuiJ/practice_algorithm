#include <iostream>

struct treeNode
{
    int key;
    treeNode *lchild;
    treeNode *rchild;

    treeNode(int tempKey)
    {
        key = tempKey;
        lchild = NULL;
        rchild = NULL;
    }
};

int res = 0;
int depth = 0;

void traverse(treeNode *root)
{
    if (root == nullptr)
    {
        res = std::max(res, depth);
        return;
    }

    depth++;
    traverse(root->lchild);
    traverse(root->rchild);
    depth--;
}

int maxDepth(treeNode *root)
{
    traverse(root);
    return res;
}

int maxDepth2(treeNode *root)
{
    if (root == nullptr)
        return 0;

    int left_max = maxDepth(root->lchild);
    int right_max = maxDepth(root->rchild);
    int res = std::max(left_max, right_max) + 1;
    return res;
}

int main()
{


    return 0;
}