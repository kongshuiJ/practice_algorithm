#include <iostream>
#include <vector>

struct treeNode
{
    int key;
    treeNode *next;
    treeNode *lchild;
    treeNode *rchild;

    treeNode(int tempKey)
    {
        key = tempKey;
        next = nullptr;
        lchild = nullptr;
        rchild = nullptr;
    }
};

void flatten(treeNode *root)
{
    if (root == nullptr)
        return;

    flatten(root->lchild);
    flatten(root->rchild);

    treeNode *left = root->lchild;
    treeNode *right = root->rchild;

    root->lchild = nullptr;
    root->rchild = left;

    treeNode *tmp = root;
    while (tmp->rchild != nullptr)
        tmp = tmp->rchild;

    tmp->rchild = right;
}

void rotatePrint(treeNode *tempNode, int tempColumn)
{
    if (nullptr == tempNode)
        return;
    rotatePrint(tempNode->lchild, tempColumn + 1);
    for (int i = 0; i < tempColumn; i++)
        std::cout << "    ";
    std::cout << "---" << tempNode->key << std::endl;
    rotatePrint(tempNode->rchild, tempColumn + 1);
}


int main()
{
    treeNode *root = new treeNode(0);
    treeNode *cur1 = new treeNode(1);
    treeNode *cur2 = new treeNode(2);
    treeNode *cur3 = new treeNode(3);
    treeNode *cur4 = new treeNode(4);
    treeNode *cur5 = new treeNode(5);
    treeNode *cur6 = new treeNode(6);

    root->lchild = cur1;
    root->rchild = cur2;

    cur1->lchild = cur3;
    cur1->rchild = cur4;

    cur2->lchild = cur5;
    cur2->rchild = cur6;

    rotatePrint(root, 0);
    flatten(root);
    printf("================\n");
    rotatePrint(root, 0);

    return 0;
}
