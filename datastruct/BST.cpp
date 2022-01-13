//
// Created by kongshui on 1/11/22.
//

#include <iostream>

struct BinarySearchTreeNode
{
    int key;
    BinarySearchTreeNode *lchild;
    BinarySearchTreeNode *rchild;

    BinarySearchTreeNode(int tempKey)
    {
        key = tempKey;
        lchild = NULL;
        rchild = NULL;
    }
};

class BinarySearchTree
{
private:
    BinarySearchTreeNode *root;

public:
    BinarySearchTree();

    BinarySearchTreeNode *getRoot();

    BinarySearchTreeNode *findBST(int key);

    void updateBSTNode(int, int);

    void insertBSTNode(int);

    bool deleteBSTNode(int);

    void deleteNoOrOneChildBSTNode(BinarySearchTreeNode *, BinarySearchTreeNode *);

    void preOrderBSTPrint(BinarySearchTreeNode *);

    void inOrderBSTPrint(BinarySearchTreeNode *);

    void sufOrderBSTPrint(BinarySearchTreeNode *);

    void rotateBSTPrint(BinarySearchTreeNode *, int);
};

BinarySearchTree::BinarySearchTree()
{
    root = nullptr;
}

BinarySearchTreeNode *BinarySearchTree::getRoot()
{
    return this->root;
}

BinarySearchTreeNode *BinarySearchTree::findBST(int tmp_key)
{
    BinarySearchTreeNode *cur = this->root;
    while (cur != nullptr)
    {
        if (cur->key == tmp_key)
            break;
        else if (cur->key > tmp_key)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }

    return cur;
}

void BinarySearchTree::insertBSTNode(int tmp_key)
{
    BinarySearchTreeNode *pre = nullptr;
    BinarySearchTreeNode *cur = root;

    while (cur != nullptr)
    {
        pre = cur;
        if (cur->key > tmp_key)
            cur = cur->lchild;
        else
            cur = cur->rchild;
    }

    BinarySearchTreeNode *tmp_node = new BinarySearchTreeNode(tmp_key);

    if (pre == nullptr)
        root = tmp_node;
    else if (pre->key > tmp_node->key)
        pre->lchild = tmp_node;
    else
        pre->rchild = tmp_node;
}

void BinarySearchTree::updateBSTNode(int old_key, int new_key)
{
    deleteBSTNode(old_key);
    insertBSTNode(new_key);
}

void BinarySearchTree::deleteNoOrOneChildBSTNode(BinarySearchTreeNode *pre, BinarySearchTreeNode *cur)
{
    if (cur->lchild != nullptr && cur->rchild != nullptr)
        return;
    else if (cur->lchild == nullptr && cur->rchild == nullptr)
    {
        if (pre == nullptr)
            root = nullptr;
        else if (pre->lchild == cur)
            pre->lchild = nullptr;
        else
            pre->rchild = nullptr;

        delete cur;
    } else if (cur->rchild != nullptr)
    {
        if (pre == nullptr)
            root = cur->rchild;
        else if (pre->lchild == cur)
            pre->lchild = cur->rchild;
        else
            pre->rchild = cur->rchild;

        delete cur;
    } else if (cur->lchild != nullptr)
    {
        if (pre == nullptr)
            root = cur->lchild;
        else if (pre->lchild == cur)
            pre->lchild = cur->lchild;
        else
            pre->rchild = cur->lchild;

        delete cur;
    }
}

bool BinarySearchTree::deleteBSTNode(int tmp_key)
{
    BinarySearchTreeNode *pre = nullptr;
    BinarySearchTreeNode *cur = root;

    while (cur != nullptr)
    {
        if (cur->key == tmp_key)
            break;
        else
        {
            pre = cur;
            if (cur->key > tmp_key)
                cur = cur->lchild;
            else
                cur = cur->rchild;
        }
    }

    if (cur == nullptr) return false;
    if (cur->lchild == nullptr || cur->rchild == nullptr)
        deleteNoOrOneChildBSTNode(pre, cur);
    else
    {
        BinarySearchTreeNode *rpre = cur;
        BinarySearchTreeNode *rcur = cur->rchild;

        while (cur->lchild != nullptr)
        {
            rpre = rcur;
            rcur = rcur->lchild;
        }
        cur->key = rcur->key;
        deleteNoOrOneChildBSTNode(rpre, rcur);
    }

    return true;
}

void BinarySearchTree::preOrderBSTPrint(BinarySearchTreeNode *tmp_root)
{
    if (tmp_root == nullptr)
        return;

    std::cout << tmp_root->key << "    ";
    preOrderBSTPrint(tmp_root->lchild);
    preOrderBSTPrint(tmp_root->rchild);
}

void BinarySearchTree::inOrderBSTPrint(BinarySearchTreeNode *tmp_root)
{
    if (tmp_root == nullptr)
        return;
    inOrderBSTPrint(tmp_root->lchild);
    std::cout << tmp_root->key << "    ";
    inOrderBSTPrint(tmp_root->rchild);
}

void BinarySearchTree::sufOrderBSTPrint(BinarySearchTreeNode *tmp_root)
{
    if (tmp_root == nullptr)
        return;
    sufOrderBSTPrint(tmp_root->lchild);
    sufOrderBSTPrint(tmp_root->rchild);
    std::cout << tmp_root->key << "    ";
}

void BinarySearchTree::rotateBSTPrint(BinarySearchTreeNode *tmp_root, int tempColumn)
{
    if (tmp_root == nullptr)
        return;
    rotateBSTPrint(tmp_root->lchild, tempColumn + 1);
    for (int i = 0; i < tempColumn; i++)
        std::cout << "    ";
    std::cout << "---" << tmp_root->key << std::endl;
    rotateBSTPrint(tmp_root->rchild, tempColumn + 1);
}

int main()
{
    int val;

    std::cout << "cin data:" << std::endl;
    while (true)
    {
        BinarySearchTree myBinarySearchTree;
        while (std::cin >> val)
        {
            if (val == 0)break;
            myBinarySearchTree.insertBSTNode(val);
        }
        std::cout << std::endl << "*****************************" << std::endl;
        myBinarySearchTree.preOrderBSTPrint(myBinarySearchTree.getRoot());
        std::cout << std::endl << "=============================" << std::endl;
        myBinarySearchTree.inOrderBSTPrint(myBinarySearchTree.getRoot());
        std::cout << std::endl << "=============================" << std::endl;
        myBinarySearchTree.sufOrderBSTPrint(myBinarySearchTree.getRoot());
        std::cout << std::endl << "=============================" << std::endl;
        myBinarySearchTree.rotateBSTPrint(myBinarySearchTree.getRoot(), 0);
        std::cout << std::endl << "*****************************" << std::endl;
        while (std::cin >> val)
        {
            if (!val)break;
            myBinarySearchTree.deleteBSTNode(val);
            std::cout << std::endl << "*****************************" << std::endl;
            myBinarySearchTree.preOrderBSTPrint(myBinarySearchTree.getRoot());
            std::cout << std::endl << "=============================" << std::endl;
            myBinarySearchTree.inOrderBSTPrint(myBinarySearchTree.getRoot());
            std::cout << std::endl << "=============================" << std::endl;
            myBinarySearchTree.sufOrderBSTPrint(myBinarySearchTree.getRoot());
            std::cout << std::endl << "=============================" << std::endl;
            myBinarySearchTree.rotateBSTPrint(myBinarySearchTree.getRoot(), 0);
            std::cout << std::endl << "*****************************" << std::endl;
        }
    }
    system("pause");
    return 0;
}