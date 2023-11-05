#pragma once

#include <iostream>
#include <new>
#include "SinglyLinkedList.h"

template<class T>
class CircularLinkedList : public SinglyLinkedList<T>, public ListNode<T>
{
private:
    ListNode<T>* traverseToTail(ListNode<T>* head)
    {
        ListNode<T>* temp = head;

        while(temp->next != this->head)
        {
            temp = temp->next;
        }

        return temp;
    }

public:
    int elementCount = 0;

    CircularLinkedList() : SinglyLinkedList<T>() {}

    CircularLinkedList(const T& value) : SinglyLinkedList<T>(value) {}

    void append(const T& data) override;
    
    void push(const T& data) override;
    
    void insert(const T& data, int index) override;
    
    void pop(void) override;
    
    void pull(void) override;
    
    void deleteAt(int index) override;

    T& tail(void) override;

    void print(void) const;

    void clear(void) override;

    ~CircularLinkedList() { this->clear(); }
};

template<class T>
void CircularLinkedList<T>::deleteAt(int index)
{
    this->error_validation(index);

    if(index == 0)
    {
        this->pull();
        return;
    }
    else if(index == (this->size() - 1))
    {
        this->pop();
        return;
    }

    ListNode<T>* temp1 = this->head;
    ListNode<T>* temp2 = nullptr;

    for(; index > 0; index--)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;

    elementCount--;
}

template<class T>
void CircularLinkedList<T>::pop(void)
{
    this->error_validation(this->default_validation_index, true, false);
    elementCount--;

    if(!this->head->next)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }

    ListNode<T>* temp1 = this->head;
    ListNode<T>* temp2 = nullptr;

    while(temp1->next != this->head)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = temp1->next;
    delete temp1;
}

template<class T>
void CircularLinkedList<T>::pull(void)
{
    this->error_validation(this->default_validation_index, true, false);

    if(this->head->next == this->head)
    {
        delete this->head;
        this->head = nullptr;
        return;
    }
    
    ListNode<T>* temp = traverseToTail(this->head);

    temp->next = this->head->next;
    delete this->head;
    this->head = temp->next;

    elementCount--;
}

template<class T>
void CircularLinkedList<T>::append(const T& data)
{
    ListNode<T>* newNode = this->createNode(data);

    if(!this->head)
    {
        this->head = newNode;
        this->head->next = this->head; // Make it circular
        return;
    }

    ListNode<T>* temp = traverseToTail(this->head);

    temp->next = newNode;
    newNode->next = this->head;
}

template<class T>
T& CircularLinkedList<T>::tail(void)
{
	// Check for error cases
	this->error_validation(this->default_validation_index, true, false);

	ListNode<T>* temp = traverseToTail(this->head);

	return temp->data;
}

template<class T>
void CircularLinkedList<T>::push(const T& data)
{
    ListNode<T>* newNode = this->createNode(data);

    if(!this->head)
    {
        this->head = newNode;
        this->head->next = this->head; // Make it circular
        return;
    }

    ListNode<T>* temp = traverseToTail(this->head);

    newNode->next = this->head;
    this->head = newNode;
    temp->next = this->head;
}

template<class T>
void CircularLinkedList<T>::insert(const T& data, int index)
{
    this->error_validation(index, false);

    if(index == (this->size() - 1))
    {
        this->append(data);
        return;
    }
    else if (index == 0)
    {
        this->push(data);
        return;
    }

    ListNode<T>* temp1 = this->head;
    ListNode<T>* temp2 = nullptr;

    ListNode<T>* newNode = this->createNode(data);

    for(; index > 0; index--)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }

    temp2->next = newNode;
    newNode->next = temp1;
}

template<class T>
void CircularLinkedList<T>::print(void) const
{
    if(this->empty())
        return;

    std::cout << "Elements of the list are: " << std::endl;

    ListNode<T>* temp = this->head;

    do
    {
        std::cout << temp->data << std::endl;
        temp = temp->next;
    } while(temp != this->head);

    std::cout << std::endl;
}

template<class T>
void CircularLinkedList<T>::clear(void)
{
    if(!this->head)
        return;

    ListNode<T>* temp = this->head;

    do
    {
        ListNode<T>* next = temp->next;
        temp->next = nullptr;

        delete temp;

        temp = next;
    } while(temp != this->head);

    this->head = nullptr;
}
