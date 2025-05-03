//Sorts a unordered binary tree to a binary search tree (BST)
#include <iostream>

struct Node
{
    int value;
    Node *rLink;
    Node *lLink;
};
typedef Node* NodePtr;

void add_node_to_right(NodePtr &parentNode, int val);
//Postcondition: Adds node to the right subtree

void add_node_to_left(NodePtr &head, int val);
//Postcondition: Add node to the left subtree

void print(NodePtr &rootNode);
//Prints all the values in the right subtree from root node

int main()
{
    NodePtr rNode;
    NodePtr rootNode = new Node;

    rNode = rootNode;
    rootNode->value = 5;
    rootNode->rLink = nullptr;
    rootNode->lLink = nullptr;

    add_node_to_right(rootNode, 13);

    print(rootNode);

    return 0;
}

void add_node_to_right(NodePtr &parentNode, int val)
{
    NodePtr tempPtr = new Node;
    tempPtr->value = val;
    parentNode->rLink = tempPtr;
    tempPtr->rLink = nullptr;
    tempPtr->lLink = nullptr;
}

void print(NodePtr &rootNode)
{
    NodePtr tempPtr;
    for (tempPtr = rootNode; tempPtr != nullptr; tempPtr = tempPtr->rLink)
    {
        std::cout << tempPtr->value << " ";
    }
}

