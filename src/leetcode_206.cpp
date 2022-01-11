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

ListNode *reverseListByIterate(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *cur = head;
    ListNode *pre = nullptr;
    ListNode *next = nullptr;

    while (cur != nullptr)
    {
        next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }

    return pre;
}

ListNode *reverseListByRecursion(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *last = reverseListByRecursion(head->next);

    head->next->next = head;
    head->next = nullptr;

    return last;
}

int main()
{
    // it is dummy node
    ListNode *head = new ListNode(1);
    ListNode *node = head;

    // it is real list
    for (int idx = 0; idx < 10; ++idx)
    {
        node->next = new ListNode(rand() % 100);
        printf(" %d ", node->next->val);

        node = node->next;
    }
    printf("\n");
//    node->next = head;

    node = reverseListByRecursion(head);

    while (node != nullptr)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

    return 0;
}