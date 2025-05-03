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

int main()
{
    NodePtr rNode;
    NodePtr rootNode = new Node;

    rNode = rootNode;
    rootNode->rLink = nullptr;
    rootNode->lLink = nullptr;

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
