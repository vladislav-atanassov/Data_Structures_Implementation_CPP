#include <iostream>
#include "SinglyLinkedList.h"
#include <string>

// Driver Code
int main()
{
    // Testing Singly Linked List
    SinglyLinkedList<std::string> myList("AAA"); 

    // Appending elements
    myList.append("BBB");
    myList.append("CCC");
    myList.append("DDD");

    // Printing elements
    myList.print();

    // Prepending elements
    myList.push("Hello");
    myList.push("World");

    // Printing elements
    myList.print();

    // Inserting at a specific position
    myList.insert("222", 2);
    myList.insert("555", 5);

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

    // Sort the elements
    myList.insertionSort(std::less<std::string>());
    
    // Printing the elements after sorting
    myList.print();

    // Clearing the list
    myList.clear();

    // Printing elements after clearing
    myList.print();

    return 0;
}