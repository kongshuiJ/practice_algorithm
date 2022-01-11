#include <iostream>

using namespace std;

struct node
{
    // 数据域
    int data;

    // 左节点
    node *lc;

    // 右结点
    node *rc;

    // 构造函数
    node() : data(0), lc(NULL), rc(NULL)
    {}

    node(int val) : data(val), lc(NULL), rc(NULL)
    {}
};

node *constructCore(int *pre, int pre_size, int *in, int in_size)
{
    if (pre_size != in_size || pre_size < 1)
        return nullptr;

    if (pre_size == 1)
        return new node(pre[0]);

    int root_node_idx = -1;

    // Find root node
    for (int idx = 0; idx < in_size; ++idx)
    {
        if (in[idx] == pre[0])
        {
            root_node_idx = idx;
            break;
        }
    }

    if (root_node_idx == -1)
        return nullptr;

    node *head = new node(pre[0]);
    int *lchild_prev = new int[root_node_idx];
    for (int idx = 0; idx < root_node_idx; ++idx)
        lchild_prev[idx] = pre[1 + idx];

    int *lchild_in = new int[root_node_idx];
    for (int idx = 0; idx < root_node_idx; ++idx)
        lchild_in[idx] = in[idx];

    head->lc = constructCore(lchild_prev, root_node_idx, lchild_in, root_node_idx);

    int rlen = in_size - 1 - root_node_idx;
    int *rchild_prev = new int[rlen];
    for (int idx = 0; idx < rlen; ++idx)
        rchild_prev[idx] = pre[root_node_idx + 1 + idx];

    int *rchild_in = new int[rlen];
    for (int idx = 0; idx < rlen; ++idx)
        rchild_in[idx] = in[root_node_idx + 1 + idx];

    head->rc = constructCore(rchild_prev, rlen, rchild_in, rlen);

    return head;
}

void printTree(node *head)
{
    if (head == nullptr)
        return;

    printTree(head->lc);
    printTree(head->rc);
    printf(" %d ", head->data);
}

// 测试代码
int main()
{
//    int prev[] = {50, 30, 10, 0, 20, 40, 70, 60, 90, 80, 100};
//    int in[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
//    node *head = constructCore(prev, 11, in, 11);

    int prev[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int in[] = {4, 7, 2, 1, 5, 3, 8, 6};
    node *head = constructCore(prev, 8, in, 8);

    printTree(head);

    return 0;
}