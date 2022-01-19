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

treeNode *build(int *inorder, int in_start, int in_end,
                int *postorder, int post_start, int post_end)
{
    if (in_start > in_end)
        return nullptr;

    int root_val = postorder[post_end];
    int index = 0;
    for (int idx = in_end; idx >= in_start; --idx)
    {
        if (inorder[idx] == root_val)
        {
            index = idx;
            break;
        }
    }

    treeNode *root = new treeNode(root_val);

    int leftSize = index - in_start;

    root->lchild = build(inorder, in_start, index - 1,
                         postorder, post_start, post_start + leftSize - 1);

    root->rchild = build(inorder, index + 1, in_end,
                         postorder, post_start + leftSize, post_end - 1);
}

treeNode *buildTree(int *inorder, int in_len, int *postorder, int post_len)
{
    return build(inorder, 0, in_len - 1, postorder, 0, post_len - 1);
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
    int inorder[] = {5, 2, 6, 4, 7, 1, 8, 3, 9};
    int postorder[] = {5, 6, 7, 4, 2, 8, 9, 3, 1};

    treeNode *root = buildTree(inorder, 9, postorder, 9);

    rotatePrint(root, 0);

    return 0;
}
