#include "tree.hpp"

int main()
{
    BstTree tree;

    //
    tree.insertNode(50);

    tree.insertNode(30);
    tree.insertNode(10);
    tree.insertNode(0);
    tree.insertNode(20);
    tree.insertNode(40);

    tree.insertNode(70);
    tree.insertNode(90);
    tree.insertNode(100);
    tree.insertNode(60);
    tree.insertNode(80);

    // 前序遍历
    std::cout << "前序遍历" << std::endl;
    tree.preOrder();
    std::cout << std::endl;

    // 中序遍历
    std::cout << "中序遍历" << std::endl;
    tree.inOrder();
    std::cout << std::endl;

    // 后序遍历
    std::cout << "后序遍历" << std::endl;
    tree.postOrder();
    std::cout << std::endl;

    std::cout << "删除结点开始，结束请输入10086" << std::endl;

    int del_key = 0;

    while (true)
    {
        std::cout << "输入删除结点值 = ";
        std::cin >> del_key;
        if (10086 == del_key)
            break;

        tree.removeNode(del_key);

        std::cout << "删除后,结点个数 = " << tree.getSize() << std::endl;
        std::cout << "删除后， 中序遍历结果:";// << std::endl;
        tree.inOrder();
        std::cout << std::endl << std::endl;
    }

    tree.removeAll();

    return 0;
}