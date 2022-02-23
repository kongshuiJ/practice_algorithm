#include <iostream>
#include <vector>
#include <set>
#include <map>

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

int res = 0;
int rank = 0;

void traverse(treeNode *root, int k)
{
    if (root == nullptr)
        return;

    traverse(root->lchild, k);

    rank++;
    if (k == rank)
    {
        res = root->key;
        return;
    }

    traverse(root->rchild, k);
}

int kthSmallest(treeNode *root, int k)
{
    traverse(root, k);
    return res;
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
    treeNode *root = new treeNode(10);
    treeNode *cur5 = new treeNode(5);
    treeNode *cur1 = new treeNode(1);
    treeNode *cur6 = new treeNode(6);
    treeNode *cur15 = new treeNode(15);
    treeNode *cur13 = new treeNode(13);
    treeNode *cur16 = new treeNode(16);

    root->lchild = cur5;
    root->rchild = cur15;

    cur5->lchild = cur1;
    cur5->rchild = cur6;

    cur15->lchild = cur13;
    cur15->rchild = cur16;

    printf("====== %d\n", kthSmallest(root, 4));

    return 0;
}
