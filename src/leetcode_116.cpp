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

void connectTwoNode(treeNode *node1, treeNode *node2)
{
    // 完美二叉树
    if (node1 == nullptr || node2 == nullptr)
        return;

    node1->next = node2;

    connectTwoNode(node1->lchild, node1->rchild);
    connectTwoNode(node2->lchild, node2->rchild);
    connectTwoNode(node1->rchild, node2->lchild);
}

treeNode *connect(treeNode *root)
{
    if (root == nullptr)
        return nullptr;
    connectTwoNode(root->lchild, root->rchild);
    return root;
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

    root = connect(root);

    printf("1 next: %d\n", cur1->next->key);
    printf("3 next: %d\n", cur3->next->key);
    printf("4 next: %d\n", cur4->next->key);
    printf("5 next: %d\n", cur5->next->key);

    rotatePrint(root, 0);

    return 0;
}
