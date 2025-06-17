//Going to add preconditions and postconditions
#include <iostream>
#include <cmath>

struct Node
{
    int value;
    Node *link;

    Node (int val) : value(val), link(nullptr) {}
};
typedef Node* NodePtr;

class LinkedList
{
public:
    NodePtr head;

    LinkedList(int val) {
        head = new Node(val);
    }

    void add_node(int val) {
        NodePtr newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        NodePtr tempPtr = head;
        while (tempPtr->link) {
            tempPtr = tempPtr->link;
        }
        tempPtr->link = newNode;
    }

    void print() {
        NodePtr tempPtr = head;
        while (tempPtr) {
            std::cout << tempPtr->value << " ";
            tempPtr = tempPtr->link;
        }
    }

    void deallocate() {
        NodePtr tempPtr = head;
        while (head) {
            head = head->link;
            delete tempPtr;
            tempPtr = head;
        }
        head = nullptr;
    }
};

int main()
{
    LinkedList l1(2);
    l1.add_node(4);
    l1.add_node(3);

    LinkedList l2(5);
    l2.add_node(6);
    l2.add_node(4);

    l1.deallocate();
    l2.deallocate();

    return 0;
}
