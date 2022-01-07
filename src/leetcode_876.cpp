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

ListNode *getMiddleNode(ListNode *head)
{
    ListNode *low = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        low = low->next;
        fast = fast->next->next;
    }

    return low;
}

int main()
{
    // it is dummy node
    ListNode *head = new ListNode(1);
    ListNode *node = head;

    // it is real list
    for (int idx = 0; idx < 11; ++idx)
    {
        node->next = new ListNode(rand() % 100);
        node = node->next;
        printf("%d ", node->val);
    }
    printf("\n");

    printf("middle node: %d\n", *getMiddleNode(head));

    return 0;
}