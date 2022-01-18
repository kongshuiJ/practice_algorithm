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

treeNode *build(int *preorder, int pre_start, int pre_end,
                int *inorder, int in_start, int in_end)
{
    if (pre_start > pre_end)
        return nullptr;

    int root_val = preorder[pre_start];
    int index = 0;
    for (int idx = in_start; idx <= in_end; ++idx)
    {
        if (inorder[idx] == root_val)
        {
            index = idx;
            break;
        }
    }

    treeNode *root = new treeNode(root_val);

    int left_size = index - in_start;

    root->lchild = build(preorder, pre_start + 1, pre_start + left_size,
                         inorder, in_start, index - 1);

    root->rchild = build(preorder, pre_start + left_size + 1, pre_end,
                         inorder, index + 1, in_end);
}

treeNode *buildTree(int *preorder, int pre_len, int *inorder, int in_len)
{
    return build(preorder, 0, pre_len - 1, inorder, 0, in_len - 1);
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
    int preorder[] = {1, 2, 5, 4, 6, 7, 3, 8, 9};
    int inorder[] = {5, 2, 6, 4, 7, 1, 8, 3, 9};

    treeNode *root = buildTree(preorder, 9, inorder, 9);

    rotatePrint(root, 0);

    return 0;
}
