#include <iostream>

int size = 1;
struct Node
{
    int value;
    Node *link;
};
typedef Node* NodePtr;

Node* initialize_list(int val)
{
    NodePtr tempPtr = new Node;
    tempPtr->value = val;
    tempPtr->link = nullptr;

    return tempPtr;
}

void add_node(NodePtr &head, int val);
//Postcondition: Added node to a LIFO data structure

void print(NodePtr &head);

void merge_lists(NodePtr &h1, NodePtr &h2);
//Postcondition: Merges two linked lists

int main()
{
    NodePtr first = initialize_list(3);
    NodePtr head = first;

    add_node(first, 6);

    print(head);

    return 0;
}

void print(NodePtr &head)
{
    NodePtr tempPtr;
    for (tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->link)
    {
        std::cout << tempPtr->value << " ";
    }
}

void add_node(NodePtr &last, int val)
{
    NodePtr tempPtr = new Node;
    tempPtr->value = val;
    last->link = tempPtr;
    last = tempPtr;
    tempPtr->link = nullptr;
    size++;
}
