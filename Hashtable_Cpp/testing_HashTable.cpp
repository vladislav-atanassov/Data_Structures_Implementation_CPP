#include <iostream>
#include "HashTable.hpp"    

int main()
{
    int arr[] = {3, 85, 7, 94, 36, 84, 3212};
    int size = sizeof(arr) / sizeof(arr[0]);

    HashTable<int> hash_table(9);

    for (int i = 0; i < size; i++)
    {
        hash_table.insert(arr[i]);
    }

    hash_table.printTable();

    hash_table.deleteAt(85);

    hash_table.printTable();

    hash_table.resizeUp();

    hash_table.printTable();

    //------------------------

    int arr2[] = {3, 85, 7, 94, 36, 84, 3212};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    HashTable<int> hash_table2(70);
    
    for (int i = 0; i < size2; i++)
    {
        hash_table2.insert(arr2[i]);
    }

    hash_table2.resizeDown();

    hash_table2.printTable();
}
