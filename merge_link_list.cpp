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

void print(NodePtr head);
//Postcondition: Prints the contents of a linked list

void deallocate_list(NodePtr &head);
//Postcondition: Deallocates memory used by linked list

Node* deep_copy(NodePtr &head);
//Postcondition: Creates a new linked list which has the same values
//but separate memory allocation from the linked list which was passed as the function argument.

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

    NodePtr first2 = initialize_list(5);
    NodePtr head2 = first2;

    add_node(first2, 12);
    add_node(first2, 18);
    add_node(first2, 19);
    add_node(first2, 22);
    add_node(first2, 14);

    NodePtr mergedHead;

    mergedHead = merge_lists(head, head2);

    print(mergedHead);

    deallocate_list(head);
    deallocate_list(head2);
    deallocate_list(mergedHead);

    return 0;
}

void print(NodePtr head)
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
    while (tempPtr != nullptr)
    {
        currentNode = tempPtr;
        tempPtr = tempPtr->link;
        delete currentNode;
    }
    head = nullptr;
}

Node* merge_lists(NodePtr h1, NodePtr h2)
{
    NodePtr head1, head2;
    NodePtr tempPtr, newHead, lastNode;

    head1 = deep_copy(h1);
    head2 = deep_copy(h2);

    newHead = head1;

    //Iterate through the first linked list
    for (tempPtr = newHead; tempPtr != nullptr; tempPtr = tempPtr->link)
    {
        if (tempPtr->link == nullptr)
            lastNode = tempPtr; //captures last node of first linked list
    }

    lastNode->link = head2; //merge linked lists

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
