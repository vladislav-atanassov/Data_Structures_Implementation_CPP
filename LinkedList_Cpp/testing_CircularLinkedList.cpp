#include <iostream>
#include "CircularLinkedList.h"

int main() 
{
    // Testing Circular Linked List
    CircularLinkedList<int> myList;

    // Appending elements
    myList.append(10);
    myList.append(20);
    myList.append(30);
    myList.append(40);

    // Printing elements
    myList.print();

    // Prepending elements
    myList.push(5);
    myList.push(0);

    // Printing elements
    myList.print();

    // Inserting at a specific position
    myList.insert(15, 2);
    myList.insert(25, 5);

    // Printing elements
    myList.print();

    // Accessing elements using index
    std::cout << "Element at index 3: " << myList[3] << std::endl;

    // Accessing the tail
    std::cout << "Tail: " << myList.tail() << std::endl;

    // Deleting at a specific position
    myList.deleteAt(4);

    // Printing elements after deletion
    myList.print();

    // Clearing the list
    myList.clear();

    // Printing elements after clearing
    myList.print();

    return 0;
}
