#pragma once

#include <iostream>
#include <list>

#define EMPTY_PLACE -1

template<class T>
class HashTable
{
private:
    // Initializing the table
    std::list<T>* table;

    // Size of the table
    int bucket;

    // Tracks the current count 
    // of elements in the table
    int elementCount;

public:
    // Constructor
    HashTable(int size)
    {
        this->bucket = size;
        table = new std::list<T>[bucket];
    };

    // Function that inserts element
    // in the table after hashing
    void insert(const T& key);

    // Funtion that deletes 
    // an element from the table 
    void deleteAt(const T& key);

    // Hashing function
    int hashFunc(const T& key, int currentBucket){return (key % currentBucket);};

    // Funtion that searches a key
    // from the table and returns 
    // the value if found
    T search(const T& key);

    // Function that return the 
    // number of elements in the table
    int lenElements() const {return elementCount;};

    // Function that returns the ratio
    // between the size of the table
    // and the number of elements in it
    float loadFactor(void) const 
    {
        return static_cast<float>(elementCount) / bucket;
    };

    // Funtion that doubles the 
    // size of the table     
    void resizeUp(void);

    // Function that sizes down 
    // the table in half
    void resizeDown(void);

    // Function that prints all 
    // of the elements in the table
    void printTable(void);

    // Destructor
    ~HashTable(){delete[] table;};
};

template<class T>
void HashTable<T>::insert(const T& key)
{
    int index = HashTable<T>::hashFunc(key, bucket);
    table[index].emplace_back(key); 
    elementCount++;
}

template<class T>
T HashTable<T>::search(const T& key) 
{
    int index = hashFunc(key, bucket);

    // Iterating through the table
    for(const T& value : table[index]) 
    {
        if(value == key)
            return key; 
    }

    throw "Element not found!\n";
}

template<class T>
void HashTable<T>::deleteAt(const T& key)
{
    int index = HashTable::hashFunc(key, bucket);

    auto& list = table[index];

    for(auto it = list.begin(); it != list.end(); it++) 
    {
        if(*it == key) 
        {
            list.erase(it);
            elementCount--;
            return;
        }
    }

    std::cerr << "Element not found!\n";
}

template<class T>
void HashTable<T>::resizeUp(void)
{
    // Check if there is a need for sizing up 
    // and if not exing the function
    if((bucket * HashTable::loadFactor()) < (bucket * 0.5f))    
    {
        std::cerr << "The threshold for resizing up is not met!\n";
        return;
    }

    int newBucket = bucket * 2;  // Double the size of the table
    std::list<T>* newTable = new std::list<T>[newBucket];

    // Rehash all existing elements into the new table
    for(int index = 0; index < bucket; index++)
    {
        for(const T& value : table[index])
        {
            int newIndex = hashFunc(value, newBucket);
            newTable[newIndex].emplace_back(value);
        }
    }

    // Free memory from the old table
    delete[] table; 

    // Assign the new data to the class variables 
    table = newTable;
    bucket = newBucket;
}

template<class T>
void HashTable<T>::resizeDown(void)
{
    // Check if there is a possibility or need 
    // for sizing down and if not exing the function
    if(bucket <= 1)
    {
        std::cerr << "Cannot resize down further.\n";
        return;
    }
    else if((bucket * HashTable::loadFactor()) > (bucket * 0.125f))
    {
        std::cerr << "The threshold for resizing down is not met!\n";
        return; 
    }

    int newBucket = bucket / 2;  // Halve the size of the table
    std::list<T>* newTable = new std::list<T>[newBucket];

    // Rehash all existing elements into the new table
    for(int index = 0; index < bucket; index++)
    {
        for(const T& value : table[index])
        {
            int newIndex = hashFunc(value, newBucket);
            newTable[newIndex].emplace_back(value);
        }
    }

    // Free memory from the old table
    delete[] table;  

    // Assign the new data to the class variables
    table = newTable;
    bucket = newBucket;
}


template<class T>
void HashTable<T>::printTable(void) 
{
    // Iterating through the table
    for(int index = 0; index < bucket; index++)
    {
        std::cout << '[' << index << ']';
        
        for(auto value : table[index])
        {
            std::cout << " -> " << value;
        }
        
        std::cout << '\n';
    }

    std::cout <<  "-------------------\n";
}