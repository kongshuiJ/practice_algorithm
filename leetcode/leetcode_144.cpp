#include <iostream>
#include <vector>

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

std::vector<int> vec;

void preOrderList(treeNode *root)
{
    if (root == nullptr)
        return;

    vec.emplace_back(root->key);
    preOrderList(root->lchild);
    preOrderList(root->rchild);
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

    preOrderList(root);

    for (int idx = 0; idx < vec.size(); ++idx)
        printf(" %d ", vec[idx]);

    return 0;
}