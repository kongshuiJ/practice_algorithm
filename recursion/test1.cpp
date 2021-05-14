//
// Created by kongshui on 5/13/21.
//

/*
 * 作者：帅地
 * 链接：https://www.zhihu.com/question/31412436/answer/683820765
 * 来源：知乎
 * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */

#include <iostream>

// 算 n 的阶乘(假设n不为0)
int factorial(int n)
{
    if (n <= 2)
    {
        return n;
    }

    return factorial(n - 1) * n;
}

/*
 * 斐波那契数列的是这样一个数列：1、1、2、3、5、8、13、21、34....
 * 即第一项 f(1) = 1,第二项 f(2) = 1.....,第 n 项目为 f(n) = f(n-1) + f(n-2)。求第 n 项的值是多少。
 */
int fibonacci_sequence(int n)
{
    if (n <= 2)
        return 1;

    return fibonacci_sequence(n - 1) + fibonacci_sequence(n - 2);
}

/*
 * 一只青蛙一次可以跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法。
 * 每次跳的时候，小青蛙可以跳一个台阶，也可以跳两个台阶，也就是说，每次跳的时候，小青蛙有两种跳法
 * 第一种跳法：第一次我跳了一个台阶，那么还剩下n-1个台阶还没跳，剩下的n-1个台阶的跳法有f(n-1)种
 * 第二种跳法：第一次跳了两个台阶，那么还剩下n-2个台阶还没，剩下的n-2个台阶的跳法有f(n-2)种
 * 所以，小青蛙的全部跳法就是这两种跳法之和了，即 f(n) = f(n-1) + f(n-2)。至此，等价关系式就求出来了。于是写出代码：
 */
int step_up(int n)
{
    if (n <= 3)
        return n;

    return step_up(n - 1) + step_up(n - 2);
}

/*
 * 反转单链表。例如链表为：1->2->3->4。反转后为 4->3->2->1
 */
class Node
{
public:
    int data;
    Node *next;

    Node(int tmp) : data(tmp), next(nullptr)
    {}
};

Node *reverse_singly_linked_list(Node *head)
{
    if ((head == nullptr) || (head->next == nullptr))
        return head;

    Node *newList = reverse_singly_linked_list(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newList;
}

int main()
{
    int t1 = 3;
    printf("%d! = %d\n", t1, factorial(t1));

    int t2 = 7;
    printf("fibonacci sequence %d: %d\n", t2, fibonacci_sequence(t2));

    int t3 = 4;
    printf("step_up %d: %d\n", t3, step_up(t3));

    Node node1(1);
    Node node2(2);
    Node node3(3);
    node1.next = &node2;
    node2.next = &node3;
    Node *t4 = reverse_singly_linked_list(&node1);
    printf("reverse_singly_linked_list : %d, %d, %d\n", t4->data, t4->next->data, t4->next->next->data);

    return 0;
}

