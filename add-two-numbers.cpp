//Suboptimal - Encounters problems with large numbers
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

    LinkedList() {
        head = nullptr;
    }

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

long long convertToDigit(LinkedList list)
{
    NodePtr iter;
    int iteration = 0;
    long long digit = 0;

    for (iter = list.head; iter != nullptr; iter = iter->link)
    {
        digit += (iter->value * (pow(10, iteration)));
        iteration++;
    }

    return digit;
}

Node* construct_list(long long num)
{
    std::string numString = std::to_string(num);
    int size = numString.size();

    int lastNumber = std::stoi(std::string(1, numString[size-1]));
    LinkedList newList(lastNumber);

    for (int i = numString.size() - 2; i >= 0; i--)
    {
        int currentNumber = std::stoi(std::string(1, numString[i]));
        newList.add_node(currentNumber);
    }

    return newList.head;
}

LinkedList addTwoNumbers(LinkedList l1, LinkedList l2)
{
    LinkedList l3;
    NodePtr p1 = l1.head;
    NodePtr p2 = l2.head;
    int carry = 0;

    while (p1 || p2 || carry) {
        int sum = carry;
        if (p1) {
            sum += p1->value;
            p1 = p1->link;
        }
        if (p2) {
            sum += p2->value;
            p2 = p2->link;
        }
        l3.add_node(sum % 10);
        carry = sum / 10;
    }

    return l3;
}

int main()
{
    LinkedList l1(9);
    l1.add_node(9);
    l1.add_node(9);
    l1.add_node(9);
    l1.add_node(9);
    l1.add_node(9);
    l1.add_node(9);

    LinkedList l2(9);
    l2.add_node(9);
    l2.add_node(9);
    l2.add_node(9);

    long long total = convertToDigit(l1) + convertToDigit(l2);

    LinkedList l3;
    l3 = addTwoNumbers(l1, l2);

    l3.print();

    l1.deallocate();
    l2.deallocate();
    l3.deallocate();

    return 0;
}
