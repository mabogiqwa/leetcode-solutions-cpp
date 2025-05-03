//Sorts a unordered binary tree to a binary search tree (BST)
#include <iostream>

struct Node
{
    int value;
    Node *rLink;
    Node *lLink;
};
typedef Node* NodePtr;

void add_node(NodePtr &head, int value);
//Postcondition: Adds nodes to the left or right link

int main()
{
    NodePtr rootNode = new Node;
    rootNode->rLink = nullptr;
    rootNode->lLink = nullptr;

    return 0;
}
