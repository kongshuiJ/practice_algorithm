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

ListNode *findFromEnd(ListNode *head, int k)
{

    ListNode *p1 = head;

    for (int idx = 0; idx < k; ++idx)
        p1 = p1->next;

    ListNode *p2 = head;

    while (p1 != nullptr)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return p2;
}

void removeNthFromEnd(ListNode *head, int k)
{
    ListNode *del_node_parent = findFromEnd(head, k + 1);
    ListNode *del_node = del_node_parent->next;

    del_node_parent->next = del_node->next;

    delete del_node;
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

    removeNthFromEnd(head, 10);

    node = head;
    while (node != nullptr)
    {
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

    return 0;
}