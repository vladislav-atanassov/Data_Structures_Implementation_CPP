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
    tree.insertInLevelOrder(84);
    tree.insertInLevelOrder(7);
    tree.insertInLevelOrder(67);
    tree.insertInLevelOrder(19);

    std::cout << "In-order traversal: ";
    tree.printInOrder(tree.treeRoot);

    tree.binaryTreeToBST(tree.treeRoot);

    std::cout << "In-order traversal: ";
    tree.printInOrder(tree.treeRoot);

    std::cout << "Number of elemnts in the list: " << 
        tree.elementCount << ", " << tree.size() << std::endl;

    return 0;
}
