#include <iostream>

struct TreeNode
{
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : value(0), left(nullptr), right(nullptr) {}
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};
typedef TreeNode* NodePtr;

void inorderTraversal(NodePtr root) {
    if (root) {
        inorderTraversal(root->left);
        std::cout << root->value << " ";
        inorderTraversal(root->right);
    }
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
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    inorderTraversal(root);

    return 0;
}
