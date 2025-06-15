#include <iostream>

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
typedef TreeNode* NodePtr;

NodePtr invertTree(NodePtr root)
{
    if (!root)
        return nullptr;

    NodePtr temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

void deleteTree(NodePtr root)
{
    if (!root)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main()
{
    NodePtr root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    NodePtr invertedRoot;

    invertedRoot = invertTree(root);

    deleteTree(root);

    return 0;
}
