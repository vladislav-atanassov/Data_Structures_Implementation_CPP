#include <iostream>
#include "Tree.h"

int main() 
{
    BinaryTree<int> tree;

    tree.insertInLevelOrder(23);
    tree.insertInLevelOrder(3);
    tree.insertInLevelOrder(2);
    tree.insertInLevelOrder(34);
    tree.insertInLevelOrder(17);
    tree.insertInLevelOrder(7);
    tree.insertInLevelOrder(67);
    tree.insertInLevelOrder(19);
    tree.insertInLevelOrder(84);

    std::cout << "In-order traversal: ";
    tree.printInOrder();

    tree.binaryTreeToBST();

    std::cout << "In-order traversal: ";
    tree.printInOrder();

    return 0;
}
