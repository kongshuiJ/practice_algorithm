//
// Created by kongshui on 1/19/22.
//

#ifndef TUTORIAL_TREE_H
#define TUTORIAL_TREE_H

#include <iostream>

struct node
{
    int data;
    node *lc;
    node *rc;

    node() : data(0), lc(nullptr), rc(nullptr)
    {}

    node(int _data) : data(_data), lc(nullptr), rc(nullptr)
    {}
};

class BstTree
{
private:
    node *root;
    int size;

public:
    enum
    {
        hmin_size_0 = 0,
        hmax_size_32767 = 32767,
    };

public:
    BstTree() : root(nullptr), size(0)
    {}

    virtual ~BstTree()
    {}

    int getSize()
    {
        return size;
    }

    void insertNode(int data)
    {
        int cur_size = getSize();
        if (hmax_size_32767 == cur_size)
        {
            std::cout << "insert node error, the size of the tree is max" << std::endl;
            return;
        }

        root = insert(root, data);
    }

    void preOrder()
    {
        preOrderTraverse(root);
    }

    void inOrder()
    {
        inOrderTraverse(root);
    }

    void postOrder()
    {
        postOrderTraverse(root);
    }

    node *query(int key)
    {
        if (root == nullptr)
        {
            std::cout << "query error, root = null" << std::endl;
            return nullptr;
        }

        return queryNode(root, key);
    }

    void removeAll()
    {
        if (root == nullptr)
        {
            std::cout << "remove all failed, root = null" << std::endl;
            return;
        }

        removeAll(root);
        int cur_size = getSize();
        if (cur_size == 0)
            root = nullptr;
    }

    void removeNode(int del_data)
    {
        if (root == nullptr)
        {
            std::cout << "remove node error, root = null" << std::endl;
            return;
        }

        node *parent_node = nullptr;
        node *del_node = root;

        while (del_node)
        {
            if (del_node->data == del_data)
                break;
            else if (del_node->data > del_data)
            {
                parent_node = del_node;
                del_node = del_node->lc;
            } else
            {
                parent_node = del_node;
                del_node = del_node->rc;
            }
        }

        if (del_node == nullptr)
        {
            std::cout << "remove node error, " << del_data << " was not find" << std::endl;
            return;
        }

        if (del_node->lc == nullptr && del_node->rc == nullptr)
        {
            if (del_node == root)
            {
                root = nullptr;
                delete del_node;
                del_node = nullptr;
                decSize();
                return;
            }

            if (del_node == parent_node->lc)
                parent_node->lc = nullptr;
            else if (del_node == parent_node->rc)
                parent_node->rc = nullptr;

            delete del_node;
            del_node = nullptr;
            decSize();
        } else if (del_node->lc != nullptr && del_node->rc == nullptr)
        {
            if (del_node == root)
                root = root->lc;
            else
            {
                if (parent_node->lc = del_node)
                    parent_node->lc = del_node->lc;
                else if (parent_node->rc == del_node)
                    parent_node->rc = del_node->lc;
            }

            delete del_node;
            del_node = nullptr;
            decSize();
        } else if (del_node->lc == nullptr && del_node->rc != nullptr)
        {
            if (del_node == root)
                root = root->rc;
            else
            {
                if (parent_node->lc = del_node)
                    parent_node->lc = del_node->rc;
                else if (parent_node->rc = del_node)
                    parent_node->rc = del_node->rc;
            }

            delete del_node;
            del_node = nullptr;
            decSize();
        } else
        {
            node *successorNode = del_node->rc;
            parent_node = del_node;

            while (successorNode->lc)
            {
                parent_node = successorNode;
                successorNode = successorNode->lc;
            }

            del_node->data = successorNode->data;
            if (successorNode == parent_node->lc)
                parent_node->lc = successorNode->rc;
            else if (successorNode = parent_node->rc)
                parent_node->rc = successorNode->rc;

            del_node = successorNode;
            delete del_node;
            del_node = nullptr;
            decSize();
        }
    }

    node *getMinNode(node *proot)
    {
        if (proot->lc == nullptr)
            return proot;
        return getMinNode(proot->lc);
    }

    node *getMaxNode(node *proot)
    {
        if (proot->rc == nullptr)
            return proot;
        return getMaxNode(proot->rc);
    }

    node *getRootNode()
    {
        return root;
    }

    node *getParentNode(int key)
    {
        node *cur_node = nullptr;
        node *parent_node = nullptr;
        cur_node = root;

        bool is_find = false;
        while (cur_node)
        {
            if (key == cur_node->data)
            {
                is_find = true;
                break;
            } else if (key < cur_node->data)
            {
                parent_node = cur_node;
                cur_node = cur_node->lc;
            } else if (key > cur_node->data)
            {
                parent_node = cur_node;
                cur_node = cur_node->rc;
            }
        }

        return is_find ? parent_node : nullptr;
    }

private:
    node *queryNode(node *proot, int key)
    {
        if (proot == nullptr)
            return proot;

        if (proot->data == key)
            return proot;
        else if (proot->data > key)
            return queryNode(proot->lc, key);
        else if (proot->data < key)
            return queryNode(proot->rc, key);

        return nullptr;
    }

    void removeAll(node *proot)
    {
        if (proot != nullptr)
        {
            removeAll(proot->lc);
            removeAll(proot->rc);
            delete proot;
            decSize();
        }
    }

    void preOrderTraverse(node *proot)
    {
        if (proot != nullptr)
        {
            std::cout << proot->data << ",   ";
            preOrderTraverse(proot->lc);
            preOrderTraverse(proot->rc);
        }
    }

    void inOrderTraverse(node *proot)
    {
        if (proot != nullptr)
        {
            inOrderTraverse(proot->lc);
            std::cout << proot->data << ",   ";
            inOrderTraverse(proot->rc);
        }
    }

    void postOrderTraverse(node *proot)
    {
        if (proot != nullptr)
        {
            postOrderTraverse(proot->lc);
            postOrderTraverse(proot->rc);
            std::cout << proot->data << ",   ";
        }
    }

    node *insert(node *proot, int data)
    {
        if (proot == nullptr)
        {
            proot = new node(data);
            return proot;
        }

        if (proot->data > data)
            proot->lc = insert(proot->lc, data);
        else if (proot->data < data)
            proot->rc = insert(proot->rc, data);

        return proot;
    }

    void addSize()
    {
        if (hmax_size_32767 == size)
            return;
        size++;
    }

    void decSize()
    {
        if (hmin_size_0 == size)
            return;

        size--;
    }
};

#endif //TUTORIAL_TREE_H
