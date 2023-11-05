#pragma once

#include <iostream>
#include <new>
#include "C:\Users\Vladislav Atanassov\Documents\Cpp_library_project\LinkedList_Cpp\SinglyLinkedList.h"
#include <set>

template<class T>
class TreeNode
{
public:
    T data;

    TreeNode<T>* left;
    TreeNode<T>* right;

    // Non-parameterized constructor
    TreeNode() : data(0), left(nullptr), right(nullptr) {}

    // Parameterized constructor
    TreeNode(const T& value) : data(value), left(nullptr), right(nullptr) {}
};

template<class T>
class BinaryTree : public TreeNode
{
public:
    // Variable that holds the first node of the binary tree
    static TreeNode<T>* treeRoot;

    // Variable that holds the number of nodes in the tree     
    int elementCount = 0;
    
    // Constructor
    BinaryTree(){ treeRoot = nullptr; };

    // Parameterized constructor
    BinaryTree(const T& value) : TreeNode(value), elementCount(1) {}
    
    // Function that calls the constructor
    // and checks if the memory is allocated properly
    TreeNode<T>* createNode(const T& data);

    // Function that prints in order the binary tree
    void printInOrder(const TreeNode<T>* root = treeRoot) const;

    // Function that returns the number
    // of nodes in the binary tree
    int size(void) const { return elementCount; };

    // Function that inserts element 
    // in the binary tree in level order
    void insertInLevelOrder(const T& data);

    // Function to insert element to
    // create a Binary Search Tree
    TreeNode<T>* insertToBST(const T& data, TreeNode<T>* root = treeRoot);

    // Function that performs the 
    // binary search algorithm
    const TreeNode<T>* binarySearchOfBTS(const T& key, const TreeNode<T>* root = treeRoot) const;

    // Function that stores the nodes 
    // with in-oredr traversal in a set
    void storeinorderInSet(std::set<int>& set, TreeNode<T>* root = treeRoot);
    
    // Function that iterates through the list and makes it
    // adds the elements in the right order to be BST
    void setToBST(std::set<int>& set, TreeNode<T>* root = treeRoot);
    
    // Copies the elemnts from the already made set and makes in BST
    void binaryTreeToBST(TreeNode<T>* root = treeRoot);

    // Function ot delete the deeepest node
    // in the binary tree
    TreeNode<T>* deleteDeepestNode(const T& key, TreeNode<T>* root = treeRoot);

    //  TODO: Create the function
    // Function and deletes the first node that has the passed key
    TreeNode<T>* deleteFirstByKeyNode(const T& key, TreeNode<T>* root = treeRoot);

    // Function that goes recursively through every node 
    // until it reaches the leaf nodes and clears them too
    void clear(TreeNode<T>* root = treeRoot);

    // Destructor
    ~BinaryTree(){ this->clear(); };
};

template<class T>
TreeNode<T>* BinaryTree<T>::treeRoot = nullptr;

template <class T>
void BinaryTree<T>::printInOrder(const TreeNode<T>* root) const
{
    if(root == nullptr)
        return;

    printInOrder(root->left);

    std::cout << root->data << ' ';
    
    printInOrder(root->right);

    if(root == treeRoot)
        std::cout << '\n';
}

template <class T>
TreeNode<T>* BinaryTree<T>::createNode(const T& value)
{
    TreeNode<T>* newNode = nullptr;

    try
    {	
		// Allocate memory and call the 
		// parameterized constructor of TreeNode
        newNode = new TreeNode<T>(value);

        if(!newNode)
        {
            throw std::runtime_error("Memory allocation failed: newNode is nullptr");
        }
    }
    catch(const std::bad_alloc& bad_al)
    {
        std::cerr << "std::bad_alloc caught: " << bad_al.what() << '\n';
        return nullptr;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Error: " << e.what() << '\n';
        return nullptr;
    }

	elementCount++;
    return newNode;
}

template<class T>
void BinaryTree<T>::insertInLevelOrder(const T& data)
{
    // If the tree is empty return a new node
    if(treeRoot == nullptr)
    {
        treeRoot = createNode(data);
        return;
    }

    SinglyLinkedList<TreeNode<T>*> queue;

    queue.push(treeRoot);  

    while(!queue.empty())
    {
        TreeNode<T>* temp = queue[0];

        queue.pop();

        if(temp->left != nullptr)
            queue.push(temp->left);
        else
        {
            temp->left = createNode(data);
            return;
        }

        if(temp->right != nullptr)
            queue.push(temp->right);
        else
        {
            temp->right = createNode(data);
            return;
        }
    }      
}

template<class T>
TreeNode<T>* BinaryTree<T>::insertToBST(const T& data, TreeNode<T>* root)
{
    // If the tree is empty return a new node
    if(root == nullptr)
        return createNode(data);
 
    // Go down the tree
    if(data < root->data)
    {
        root->left = insertToBST(data, root->left);
    }
    else if(data > root->data)
    {
        root->right = insertToBST(data, root->right);
    }

    return root;
}

template<class T>
const TreeNode<T>* BinaryTree<T>::binarySearchOfBTS(const T& key, const TreeNode<T>* root) const
{
    // If the tree is empty return nullptr
    if(!root)
        return nullptr;  

    // If searched key is of the root return root
    if(root->data == key)
        return root;

    // Recursive Binary search algotithm 
    if(key < root->data)
        return binarySearchOfBTS(key, root->left);
    else
        return binarySearchOfBTS(key, root->right);
}

template<class T>
void BinaryTree<T>::storeinorderInSet(std::set<int>& set, TreeNode<T>* root)
{
    if(!root)
        return;
 
    // visit the left subtree first
    storeinorderInSet(set, root->left);
 
    // insertion takes order of O(logn) for sets
    set.insert(root->data);
 
    // visit the right subtree
    storeinorderInSet(set, root->right);
 
} 

template<class T>
void BinaryTree<T>::setToBST(std::set<int>& set, TreeNode<T>* root)
{
    if(!root)
        return;
 
    // first move to the left subtree and
    // update items
    setToBST(set, root->left);
 
    // iterator initially pointing to the
    // beginning of set
    auto it = set.begin();
 
    // copying the item at beginning of
    // set(sorted) to the tree.
    root->data = *it;
 
    // now erasing the beginning item from set.
    set.erase(it);
 
    // now move to right subtree and update items
    setToBST(set, root->right);
}
 
template<class T>
void BinaryTree<T>::binaryTreeToBST(TreeNode<T>* root)
{
    std::set<int> set;
 
    // Fill the tree
    storeinorderInSet(set, root);
 
    // Copying items from set to the tree
    setToBST(set, root);
}

template<class T>
TreeNode<T>* BinaryTree<T>::deleteDeepestNode(const T& key, TreeNode<T>* root)
{
    // If the tree is empty 
    if(!root) 
        return nullptr;

    // Check if the tree has child nodes
    if(root->left == nullptr && root->right == nullptr) 
    {
        // Check if the key is the searched one
        // and if not return the root
        if(root->data == key)
            return nullptr;
        else
            return root;
    }

    TreeNode<T>* temp = nullptr;
    TreeNode<T>* key_node = nullptr;
    TreeNode<T>* last = nullptr;
    
    SinglyLinkedList<TreeNode<T>*> queue;

    queue.push(root);

    // Do level order traversal to find deepest
    // node(temp), node to be deleted (key_node)
    // and parent of deepest node(last)
    while(!queue.empty())
    {
        temp = queue[0];

        queue.pop();

        if(temp->data == key)
            key_node = temp;
 
        if(temp->left)
        {
            last = temp;    // storing the parent node
            queue.push(temp->left);
        }
 
        if(temp->right)
        {
            last = temp;    // storing the parent node
            queue.push(temp->right);
        }
    }

    try
    {
        // Check if last is the deepest node 
        if(last->left == nullptr && last->right == nullptr)
        {
            //Check if the passed argument "key" is valid
            if(last->data != key)
            {
                throw std::invalid_argument("The key is not of the deepest node in the binary tree!");
            }
        }
        // Check if last's right child is the deepest node and
        // check if the passed argument "key" is valid
        else if(last->right && last->right->data != key)
        {
            throw std::invalid_argument("The key is not of the deepest node in the binary tree!");
        }
    }
    catch(const std::invalid_argument& inv_arg)
    {
        std::cerr << "Invalid argument: " << inv_arg.what() << '\n';
        return nullptr;
    }

    if(key_node != nullptr) 
    {
        // replacing key_node's data to deepest node's data
        key_node->data = temp->data; 

        if(last->right == temp)
            last->right = nullptr;
        else
            last->left = nullptr;

        delete temp;
    }

    elementCount--;

    return root;
}

template<class T>
TreeNode<T>* BinaryTree<T>::deleteFirstByKeyNode(const T& key, TreeNode<T>* root)
{
      
}

template<class T>
void BinaryTree<T>::clear(TreeNode<T>* root)
{
    if(root != nullptr)
    {
        clear(root->left);
        clear(root->right);
        delete root;
    }

    if(root == treeRoot)
        treeRoot = nullptr;
}
