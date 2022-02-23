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

ListNode *successor = nullptr;

// Reverse the first N nodes of the linked list
ListNode *reverseFirstN(ListNode *head, int n)
{
    if (n == 1)
    {
        successor = head->next;
        return head;
    }
    ListNode *last = reverseFirstN(head->next, n - 1);

    head->next->next = head;
    head->next = successor;

    return last;
}

ListNode *reverseBetween(ListNode *head, int m, int n)
{
    if (m == 1)
    {
        return reverseFirstN(head, n);
    }

    head->next = reverseBetween(head->next, m - 1, n - 1);
    return head;
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

    node = reverseBetween(head, 3, 5);

    while (node != nullptr)
    {
        printf("%3d ", node->val);
        node = node->next;
    }
    printf("\n");

    return 0;
}