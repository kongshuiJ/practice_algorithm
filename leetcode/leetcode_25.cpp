//
// Created by kongshui on 5/17/21.
//
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <array>
#include <queue>

struct ListNode
{
    int val;
    struct ListNode *next;

    ListNode(int v) : val(v), next(nullptr)
    {}
};

ListNode *reverse(ListNode *a, ListNode *b)
{
    ListNode *pre = nullptr;
    ListNode *cur = a;
    ListNode *nxt = a;

    while (cur != b)
    {
        nxt = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nxt;
    }

    return pre;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *a = head;
    ListNode *b = head;

    for (int idx = 0; idx < k; ++idx)
    {
        if (b == nullptr) return head;
        b = b->next;
    }

    ListNode *newHead = reverse(a, b);
    a->next = reverseKGroup(b, k);

    return newHead;
}

int main()
{
    // it is dummy node
    ListNode *head = new ListNode(1);
    ListNode *node = head;

    // it is real list
    printf("%3d ", node->val);
    for (int idx = 0; idx < 10; ++idx)
    {
        node->next = new ListNode(rand() % 100);
        printf("%3d ", node->next->val);

        node = node->next;
    }
    printf("\n");
//    node->next = head;

    node = reverseKGroup(head, 11);

    while (node != nullptr)
    {
        printf("%3d ", node->val);
        node = node->next;
    }
    printf("\n");

    return 0;
}