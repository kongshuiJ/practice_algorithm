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

ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
{
    ListNode *p1 = head1;
    ListNode *p2 = head2;

    while (p1 != p2)
    {
        if (p1 == nullptr) p1 = head2;
        else p1 = p1->next;

        if (p2 == nullptr) p2 = head1;
        else p2 = p2->next;
    }

    return p1;
}

int main()
{
    // it is dummy node
    ListNode *head1 = new ListNode(1);
    ListNode *node1 = head1;

    ListNode *head2 = new ListNode(2);
    ListNode *node2 = head2;

    // it is real list
    for (int idx = 0; idx < 10; ++idx)
    {
        node1->next = new ListNode(rand() % 100);
        if (idx > 5)
        {
            node2->next = node1->next;
            node2 = node2->next;
        }
        printf(" %d ", node1->next->val);

        node1 = node1->next;
    }
    printf("\n");
//    node->next = head1;

    printf("has cycle %d\n", getIntersectionNode(head1, head2)->val);

    return 0;
}