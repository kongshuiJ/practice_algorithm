#include <iostream>

struct AVLTreeNode
{
    int key;
    int height;
    AVLTreeNode *lchild;
    AVLTreeNode *rchild;

    AVLTreeNode(int tmp_key)
    {
        height = 0;
        key = tmp_key;
        lchild = nullptr;
        rchild = nullptr;
    }
};

class AVLTree
{
private:
    AVLTreeNode *root;
    AVLTreeNode *searchKey(int, AVLTreeNode *);
    AVLTreeNode *leftRotate(AVLTreeNode *);
    AVLTreeNode *leftAndRightRotate(AVLTreeNode *);
    AVLTreeNode *rightRotate(AVLTreeNode *);
    AVLTreeNode *rightAndLeftRotate(AVLTreeNode *);

    int getHeight(AVLTreeNode *);
    void preOrderPrint(AVLTreeNode *);
    void inOrderPrint(AVLTreeNode *);
    void sufOrderPrint(AVLTreeNode *);
    void rotatePrint(AVLTreeNode *, int);
    AVLTreeNode *insertKey(int, AVLTreeNode *);
    AVLTreeNode *deleteKey(bool &, int, AVLTreeNode *);

public:
    AVLTree();
    void insertKey(int);
    bool searchKey(int);
    bool deleteKey(int);
    bool updata(int, int);
    void preOrderPrint();
    void inOrderPrint();
    void sufOrderPrint();
    void rotatePrint();
};

AVLTree::AVLTree()
{
    root = nullptr;
}

int AVLTree::getHeight(AVLTreeNode *tmp_node)
{
    return tmp_node == nullptr ? -1 : tmp_node->height;
}

AVLTreeNode *AVLTree::searchKey(int tmp_key, AVLTreeNode *tmp_node)
{
    if (tmp_node == nullptr)
        return nullptr;
    else if (tmp_key == tmp_node->key)
        return tmp_node;
    else if (tmp_key < tmp_node->key)
        return searchKey(tmp_key, tmp_node->lchild);
    else
        return searchKey(tmp_key, tmp_node->rchild);
}

bool AVLTree::searchKey(int tmp_key)
{
    return searchKey(tmp_key, root) != nullptr ? true : false;
}

AVLTreeNode *AVLTree::leftRotate(AVLTreeNode *tmp_node)
{
    AVLTreeNode *lchild_node = tmp_node->rchild->lchild;
    AVLTreeNode *new_root = tmp_node->rchild;
    tmp_node->rchild->lchild = tmp_node;
    tmp_node->rchild = lchild_node;
    tmp_node->height = std::max(getHeight(tmp_node->lchild),
                                getHeight(tmp_node->rchild)) + 1;
    if (tmp_node->rchild != nullptr)
    {
        tmp_node->rchild->height =
                std::max(getHeight(tmp_node->rchild->lchild),
                         getHeight(tmp_node->rchild->rchild)) + 1;
    }

    return new_root;
}

AVLTreeNode *AVLTree::rightRotate(AVLTreeNode *tmp_node)
{
    AVLTreeNode *rchild_node = tmp_node->lchild->rchild;
    AVLTreeNode *new_root = tmp_node->lchild;
    tmp_node->lchild->rchild = tmp_node;
    tmp_node->lchild = rchild_node;
    tmp_node->height = std::max(getHeight(tmp_node->lchild),
                                getHeight(tmp_node->rchild)) + 1;

    if (tmp_node->lchild != nullptr)
    {
        tmp_node->lchild->height = std::max(getHeight(tmp_node->lchild->lchild),
                                            getHeight(tmp_node->lchild->rchild)) + 1;
    }

    return new_root;
}

AVLTreeNode *AVLTree::leftAndRightRotate(AVLTreeNode *tmp_node)
{
    tmp_node->lchild = leftRotate(tmp_node->lchild);
    return rightRotate(tmp_node);
}

AVLTreeNode *AVLTree::rightAndLeftRotate(AVLTreeNode *tmp_node)
{
    tmp_node->rchild = rightRotate(tmp_node->rchild);
    return leftRotate(tmp_node);
}

AVLTreeNode *AVLTree::insertKey(int tmp_key, AVLTreeNode *tmp_node)
{
    if (tmp_node == nullptr)
    {
        tmp_node = new AVLTreeNode(tmp_key);
        return tmp_node;
    } else
    {
        if (tmp_key == tmp_node->key)
            return tmp_node;
        else if (tmp_key < tmp_node->key)
            tmp_node->lchild = insertKey(tmp_key, tmp_node->lchild);
        else
            tmp_node->rchild = insertKey(tmp_key, tmp_node->rchild);
    }

    if (getHeight(tmp_node->lchild) - getHeight(tmp_node->rchild) == 2)
    {
        if (tmp_key < tmp_node->lchild->key)
            tmp_node = rightRotate(tmp_node);
        else tmp_node = leftAndRightRotate(tmp_node);
    } else if (getHeight(tmp_node->lchild) - getHeight(tmp_node->rchild) == -2)
    {
        if (tmp_key > tmp_node->rchild->key)
            tmp_node = leftRotate(tmp_node);
        else tmp_node = rightAndLeftRotate(tmp_node);
    }

    tmp_node->height = std::max(getHeight(tmp_node->lchild), getHeight(tmp_node->rchild)) + 1;
    return tmp_node;
}

void AVLTree::insertKey(int tmp_key)
{
    root = insertKey(tmp_key, root);
}

AVLTreeNode *AVLTree::deleteKey(bool &is_del_succeed, int tmp_key, AVLTreeNode *tmp_node)
{
    if (tmp_node == nullptr)
        return nullptr;

    if (tmp_key == tmp_node->key)
    {
        if (tmp_node->rchild == nullptr)
        {
            AVLTreeNode *cur = tmp_node;
            tmp_node = tmp_node->lchild;
            delete cur;
            is_del_succeed = true;
            return tmp_node;
        } else
        {
            AVLTreeNode *cur = tmp_node->rchild;
            while (cur->lchild != nullptr)
                cur = cur->lchild;
            tmp_node->key = cur->key;
            tmp_node->rchild = deleteKey(is_del_succeed, cur->key, tmp_node->rchild);
        }
    } else if (tmp_key < tmp_node->key)
        tmp_node->lchild = deleteKey(is_del_succeed, tmp_key, tmp_node->lchild);
    else
        tmp_node->rchild = deleteKey(is_del_succeed, tmp_key, tmp_node->rchild);

    if (getHeight(tmp_node->lchild) - getHeight(tmp_node->rchild) == 2)
    {
//        if (getHeight(tmp_node->lchild->lchild) >= getHeight(tmp_node->lchild->rchild))
//            tmp_node = rightRotate(tmp_node);
//        else tmp_node = leftAndRightRotate(tmp_node);

        if (tmp_key < tmp_node->lchild->key)
            tmp_node = rightRotate(tmp_node);
        else tmp_node = leftAndRightRotate(tmp_node);
    } else if (getHeight(tmp_node->lchild) - getHeight(tmp_node->rchild) == -2)
    {
        printf("====== %d\n", tmp_node->key);

        if (tmp_key > tmp_node->rchild->key)
            tmp_node = leftRotate(tmp_node);
        else tmp_node = rightAndLeftRotate(tmp_node);
//        if (getHeight(tmp_node->rchild->rchild) >= getHeight(tmp_node->rchild->lchild))
//            tmp_node = leftRotate(tmp_node);
//        else tmp_node = rightAndLeftRotate(tmp_node);
    }

    tmp_node->height = std::max(getHeight(tmp_node->lchild), getHeight(tmp_node->rchild)) + 1;
    return tmp_node;
}

bool AVLTree::deleteKey(int tmp_key)
{
    bool is_del_succeed = false;
    root = deleteKey(is_del_succeed, tmp_key, root);
    return is_del_succeed;
}

bool AVLTree::updata(int old_key, int new_key)
{
    if (deleteKey(old_key))
    {
        insertKey(new_key);
        return true;
    }
    return false;
}

void AVLTree::preOrderPrint(AVLTreeNode *tmp_node)
{
    if (tmp_node == nullptr)
        return;
    std::cout << tmp_node->key << "    ";
    preOrderPrint(tmp_node->lchild);
    preOrderPrint(tmp_node->rchild);
}

void AVLTree::preOrderPrint()
{
    preOrderPrint(root);
}

void AVLTree::inOrderPrint(AVLTreeNode *tmp_node)
{
    if (tmp_node == nullptr)
        return;

    inOrderPrint(tmp_node->lchild);
    std::cout << tmp_node->key << "    ";
    inOrderPrint(tmp_node->rchild);
}

void AVLTree::inOrderPrint()
{
    inOrderPrint(root);
}

void AVLTree::sufOrderPrint(AVLTreeNode *tmp_node)
{
    if (tmp_node == nullptr)
        return;

    sufOrderPrint(tmp_node->lchild);
    sufOrderPrint(tmp_node->rchild);
    std::cout << tmp_node->key << "    ";
}

void AVLTree::sufOrderPrint()
{
    sufOrderPrint(root);
}

void AVLTree::rotatePrint(AVLTreeNode *tempNode, int tempColumn)
{
    if (nullptr == tempNode)
        return;
    rotatePrint(tempNode->lchild, tempColumn + 1);
    for (int i = 0; i < tempColumn; i++)
        std::cout << "    ";
    std::cout << "---" << tempNode->key << std::endl;
    rotatePrint(tempNode->rchild, tempColumn + 1);
}

void AVLTree::rotatePrint()
{
    rotatePrint(root, 0);
}

void Menu()
{
    int val, choice, newVal;
    AVLTree myAVLTree;
    while (true)
    {
        do
        {
            std::cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << std::endl;
            std::cout << "       1.插入" << std::endl;
            std::cout << "       2.删除" << std::endl;
            std::cout << "       3.修改" << std::endl;
            std::cout << "       4.查找" << std::endl;
            std::cout << "       5.显示" << std::endl;
            std::cout << "       6.返回" << std::endl;
            std::cout << "请输入你的选项[ ]\b\b";
            std::cin >> choice;
        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6);

        switch (choice)
        {
            case 1:
            {
                std::cin >> val;
                myAVLTree.insertKey(val);
                break;
            }
            case 2:
            {
                std::cin >> val;
                if (myAVLTree.deleteKey(val))
                    std::cout << "删除成功!" << std::endl;
                else std::cout << "删除失败!" << std::endl;
                break;
            }
            case 3:
            {
                std::cin >> val >> newVal;
                if (myAVLTree.updata(val, newVal))
                    std::cout << "修改成功!" << std::endl;
                else std::cout << "修改失败!" << std::endl;
                break;
            }
            case 4:
            {
                std::cin >> val;
                if (myAVLTree.searchKey(val))
                    std::cout << "查找成功!" << std::endl;
                else std::cout << "查找失败!" << std::endl;
                break;
            }
            case 5:
            {
                std::cout << std::endl << "*****************************" << std::endl;
                std::cout << std::endl << "==========前序==============" << std::endl;
                myAVLTree.preOrderPrint();
                std::cout << std::endl << "==========中序================" << std::endl;
                myAVLTree.inOrderPrint();
                std::cout << std::endl << "==========后续===============" << std::endl;
                myAVLTree.sufOrderPrint();
                std::cout << std::endl << "==========对称+旋转===============" << std::endl;
                myAVLTree.rotatePrint();
                std::cout << std::endl << "*****************************" << std::endl;
                break;
            }
            default:
                return;
        }
    }
}

void test_case1()
{
    AVLTree tree;
    tree.insertKey(100);
    tree.insertKey(50);
    tree.insertKey(120);
    tree.insertKey(40);
    tree.insertKey(110);
    tree.insertKey(60);
    tree.insertKey(150);
    tree.insertKey(70);
    tree.insertKey(105);
    tree.insertKey(115);
    tree.insertKey(112);
    tree.insertKey(111);
    tree.deleteKey(100);

    tree.rotatePrint();
}

void test_case2()
{
    AVLTree tree;
    tree.insertKey(1);
    tree.insertKey(2);
    tree.insertKey(3);
    tree.insertKey(4);
    tree.insertKey(5);
    tree.insertKey(6);
    tree.insertKey(7);

    tree.rotatePrint();
}

int main()
{
    test_case2();

//    while (true)
//        Menu();
    return 0;
}














