#include <iostream>
#include <algorithm>

int size = 1; //keeps track of linked list size
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

void deallocate_list(NodePtr &head);
//Postcondition: Deallocates memory used by linked list

void reverse_list(NodePtr head);
//Postcondition: Reverses a linked list

void print(NodePtr &head);

int main()
{
    NodePtr head;

    NodePtr first = new Node;
    //first->value = 3;
    //first->link = nullptr;
    //head = first;

    first = initialize_list(3);

    add_node(first, 2);
    add_node(first, 5);
    add_node(first, 6);
    add_node(first, 5);
    add_node(first, 4);

    print(head);

    reverse_list(head);

    deallocate_list(head);

    return 0;
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

void reverse_list(NodePtr head)
{
    NodePtr listArr[size];
    NodePtr tempPtr, newHead;
    int index = 0;
    int lastIndex = size - 1;

    for (tempPtr = head; tempPtr != nullptr; tempPtr=tempPtr->link) { listArr[index] = tempPtr; index++;} //Stores the memory locations of each node in an array index position

    std::reverse(listArr, listArr + size); //Array is reversed

    for(int i = 0; i < size; i++)
    {
        if (i == 0) { newHead = listArr[i]; }

        if (i <= (size - 2)) { listArr[i]->link = listArr[i+1]; }

        if (i == (size-1)) {
                listArr[i]->link = nullptr;
        }
    } //Uses a for loop to link all the memory locations to create a linked list from the reversed array

    std::cout << std::endl;
    print(newHead);
    deallocate_list(newHead);
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

void print(NodePtr &head)
{
    NodePtr tempPtr;
    for (tempPtr = head; tempPtr != nullptr; tempPtr = tempPtr->link)
    {
        std::cout << tempPtr->value << " ";
    }
}
