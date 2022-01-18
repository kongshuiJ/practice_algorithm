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

treeNode *constructMaximumBinaryTree(int *nums, int len)
{
    if (len <= 0)
        return nullptr;
    int max_idx = 0;
    int max_val = nums[0];

    for (int idx = 1; idx < len; ++idx)
    {
        if (nums[idx] > max_val)
        {
            max_idx = idx;
            max_val = nums[idx];
        }
    }

    treeNode *root = new treeNode(max_val);

    root->lchild = constructMaximumBinaryTree(nums, max_idx);
    root->rchild = constructMaximumBinaryTree(nums + max_idx + 1, len - max_idx - 1);

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
    int nums[] = {3, 2, 1, 6, 0, 5};

    treeNode *root = constructMaximumBinaryTree(nums, sizeof(nums) / sizeof(int));

    rotatePrint(root, 0);

    return 0;
}
