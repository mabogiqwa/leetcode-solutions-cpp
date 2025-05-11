//Sorts a unordered binary tree to a binary search tree (BST)
//Incomplete
#include <iostream>
#include <vector>

struct Node
{
    int value;
    Node *rLink;
    Node *lLink;
};
typedef Node* NodePtr;

std::vector<NodePtr> rightParentNodes;

std::vector<NodePtr> leftParentNodes;

void add_node_to_right(NodePtr &parentNode, int val);
//Postcondition: Adds node to the right subtree

void add_node_to_left(NodePtr &head, int val);
//Postcondition: Add node to the left subtree

void print(NodePtr &rootNode);
//Prints all the values in the right subtree from root node

Node* construct_binary_tree();
//Postcondition: Creates a pre-defined binary tree

int main()
{
    NodePtr rootNode = construct_binary_tree();

    std::cout << rootNode->rLink->value;

    return 0;
}

Node* construct_binary_tree()
{
    NodePtr rNode;
    NodePtr rootNode = new Node; //tracks the last added node

    rightParentNodes.push_back(rootNode);

    rNode = rootNode;
    rootNode->value = 10;
    rootNode->rLink = nullptr;
    rootNode->lLink = nullptr;

    //Constructing right subtree from the root node
    add_node_to_right(rootNode, 2);
    rightParentNodes.push_back(rootNode);
    add_node_to_right(rootNode, 4);
    rightParentNodes.push_back(rootNode);
    add_node_to_right(rootNode, 101);
    rightParentNodes.push_back(rootNode);

    NodePtr leftNode = rightParentNodes[1];
    add_node_to_left(leftNode, 3);
    leftNode = leftNode->lLink;
    add_node_to_left(leftNode, -1);
    add_node_to_right(leftNode, 10);

    add_node_to_left(rightParentNodes[2], 55);
    //Right subtree complete

    //Constructing left subtree from the root node
    rootNode = rightParentNodes[0];

    add_node_to_left(rootNode, 11);
    rootNode = rootNode->lLink;
    leftParentNodes.push_back(rootNode);
    add_node_to_left(rootNode, 56);
    rootNode = rootNode->lLink;
    leftParentNodes.push_back(rootNode);
    add_node_to_left(rootNode, 5);
    rootNode = rootNode->lLink;
    leftParentNodes.push_back(rootNode);

    rootNode = leftParentNodes[1];
    add_node_to_right(rootNode, 100);

    rootNode = leftParentNodes[0];
    add_node_to_right(rootNode, 17);
    add_node_to_left(rootNode, 12);
    add_node_to_right(rootNode, 0);

    return rNode;
}

void add_node_to_right(NodePtr &parentNode, int val)
{
    NodePtr tempPtr = new Node;
    tempPtr->value = val;
    parentNode->rLink = tempPtr;
    parentNode = tempPtr;
    tempPtr->rLink = nullptr;
    tempPtr->lLink = nullptr;
}

void add_node_to_left(NodePtr &parentNode, int val)
{
    NodePtr tempPtr = new Node;
    tempPtr->value = val;
    parentNode->lLink = tempPtr;
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

