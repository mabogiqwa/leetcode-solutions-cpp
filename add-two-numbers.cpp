//Going to add preconditions and postconditions
#include <iostream>
#include <cmath>

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

void add_node(NodePtr &currentNode, int val)
{
    NodePtr tempPtr = new Node;
    tempPtr->value = val;
    currentNode->link = tempPtr;
    currentNode = tempPtr;
    tempPtr->link = nullptr;
}

int size(NodePtr head)
{
    NodePtr iter;
    int size = 0;
    for (iter = head; iter != nullptr; iter = iter->link)
    {
        size++;
    }

    return size;
}

void print(NodePtr head)
{
    NodePtr iter;
    for (iter = head; iter != nullptr; iter = iter->link)
    {
        std::cout << iter->value << " ";
    }
}

void deallocate(NodePtr &head)
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

//This is the function that gives the output to the two lists
Node* construct_list(long long num)
{
    std::string numString = std::to_string(num);
    int size = numString.size();

    int lastNumber = std::stoi(std::string(1, numString[size-1]));
    NodePtr currentPtr = initialize_list(lastNumber);
    NodePtr head = currentPtr;

    for (int i = numString.size() - 2; i >= 0; i--)
    {
        int currentNumber = std::stoi(std::string(1, numString[i]));
        add_node(currentPtr, currentNumber);
    }

    return head;
}

long long convert_to_digit(NodePtr head)
{
    NodePtr iter;
    int iteration = 0;
    long long digit = 0;

    for (iter = head; iter != nullptr; iter = iter->link)
    {
        digit += (iter->value * (pow(10, iteration)));
        iteration++;
    }

    return digit;
}

int main()
{
    NodePtr currentNode = initialize_list(2); //first list
    NodePtr head = currentNode;

    add_node(currentNode, 4);
    add_node(currentNode, 3);

    NodePtr currentNode2 = initialize_list(5);
    NodePtr head2 = currentNode2;

    add_node(currentNode2, 6);
    add_node(currentNode2, 4);

    long long total = convert_to_digit(head) + convert_to_digit(head2);

    NodePtr head3 = construct_list(total);

    print(head3);

    deallocate(head);
    deallocate(head2);

    return 0;
}
