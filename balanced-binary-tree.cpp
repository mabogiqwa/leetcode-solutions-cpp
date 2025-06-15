#include <iostream>
#include <algorithm>
#include <cmath>

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
typedef TreeNode* NodePtr;

//Post-order traversal
int checkHeight(NodePtr node, bool &isBalanced)
{
    if (!node)
        return 0;

    int leftHeight = checkHeight(node->left, isBalanced);
    int rightHeight = checkHeight(node->right, isBalanced);

    std::cout << node->value << std::endl;

    if (abs(leftHeight - rightHeight) > 1)
        isBalanced = false;

    return std::max(leftHeight, rightHeight) + 1;
}

bool isBalanced(NodePtr root)
{
    bool balanced = true;
    checkHeight(root, balanced);

    return balanced;
}

void deleteTree(NodePtr node)
{
    if(!node)
        return;

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
}

int main()
{
    NodePtr root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(3);
    root->left->left = new TreeNode(3);
    root->left->left->right = new TreeNode(4);
    root->left->left->left = new TreeNode(4);


    if (isBalanced(root))
        std::cout << "The tree is balanced." << std::endl;
    else
        std::cout << "The tree is not balanced." << std::endl;

    deleteTree(root);

    return 0;
}

