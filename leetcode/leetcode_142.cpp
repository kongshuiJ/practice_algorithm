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

ListNode *getCycleNode(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    if (fast == nullptr || fast->next == nullptr)
        return nullptr;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
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
        node = node->next;
        printf("%d ", node->val);
    }
    printf("\n");
    node->next = head->next->next;

    printf("cycle node: %d\n", *getCycleNode(head));

    return 0;
}