#include <iostream>

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

void deallocate_list(NodePtr &head);

Node* deep_copy(NodePtr &head);

//Version 1
Node* merge_lists(NodePtr h1, NodePtr h2);
//Precondition: Pass the first pointer of the first list and the head of the second list
//Postcondition: Returns a merged list of the two linked lists

int main()
{
    NodePtr first = initialize_list(3);
    NodePtr head = first;

    add_node(first, 4);
    add_node(first, 7);
    add_node(first, 2);
    add_node(first, 1);
    add_node(first, 10);

    NodePtr newHead = deep_copy(head);

    print(newHead);

    /*
    NodePtr first2 = initialize_list(5);
    NodePtr head2 = first2;

    add_node(first2, 12);
    add_node(first2, 18);
    add_node(first2, 19);
    add_node(first2, 22);
    add_node(first2, 14);
    */

    return 0;
}

void print(NodePtr &head)
{
    NodePtr tempPtr;
    for (tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->link)
    {
        std::cout << tempPtr->value << " ";
    }
    std::cout << std::endl;
}

void add_node(NodePtr &last, int val)
{
    NodePtr tempPtr = new Node;
    tempPtr->value = val;
    last->link = tempPtr;
    last = tempPtr;
    tempPtr->link = nullptr;
}

void deallocate_list(NodePtr &head)
{
    NodePtr tempPtr = head;
    NodePtr currentNode;
    while (tempPtr->link != nullptr)
    {
        currentNode = tempPtr;
        tempPtr = tempPtr->link;
        delete currentNode;
    }
    head = nullptr;
}

Node* merge_lists(NodePtr h1, NodePtr h2)
{
    NodePtr newHead = h1;
    NodePtr tempPtr, lastNode;

    //Deep copy
    for (tempPtr = newHead; tempPtr != nullptr; tempPtr = tempPtr->link)
    {

    }

    //Iterate through the first linked list
    for (tempPtr = newHead; tempPtr != nullptr; tempPtr = tempPtr->link)
    {
        if (tempPtr->link == nullptr)
            lastNode = tempPtr;
    }

    lastNode->link = h2; //merge linked lists

    return newHead;
}

Node* deep_copy(NodePtr &head)
{
    NodePtr tempPtr, last;
    NodePtr newHead;
    int index = 0;

    tempPtr = head;
    last = initialize_list(tempPtr->value); //initialize new linked list
    newHead = last;

    for (tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->link)
    {
        if (index > 0) {
            add_node(last, tempPtr->value);
        }
        index++;
    }

    return newHead;
}
