//
// Created by kongshui on 5/18/21.
//

/**
 * 给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：
 * 二叉树的根是数组 nums 中的最大元素。
 * 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
 * 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
 * 返回有给定数组 nums 构建的 最大二叉树 。
 */

#include <iostream>
#include <vector>
#include <atomic>
#include <memory>
#include <typeinfo>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr)
    {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {}
};

class Solution
{
public:
    TreeNode *constructMaximumBinaryTree(std::vector<int> &nums)
    {
        if (nums.empty())
            return nullptr;

        int max_val     = nums[0];
        int max_val_idx = 0;

        for (int index = 0; index < nums.size(); ++index)
        {
            if(nums[index] >max_val)
            {
                max_val     = nums[index];
                max_val_idx = index;
            }
        }

        TreeNode *node = new TreeNode(max_val);

        std::vector<int> left_vecl(std::vector<int>(nums.begin(), nums.begin() + max_val_idx));
        std::vector<int> right_vec(std::vector<int>(nums.begin() + max_val_idx, nums.end()));

        node->left  = constructMaximumBinaryTree(left_vec);
        node->right = constructMaximumBinaryTree(right_vec);

        return node;
    }
};

int main()
{
    Solution tmp;
    std::vector<int> input{3,2,1,6,0,5};

    auto result = tmp.constructMaximumBinaryTree(input);

    return 0;
}