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

void postOrderTraversal(NodePtr root) {
    if(root) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->value << " ";
    } else {
        return;
    }
}

void deleteTree(NodePtr root)
{
    if(!root)
        return;

    deleteTree(root->left);
    deleteTree(root->right);

    delete root;
}

int main()
{
    NodePtr root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->right = new TreeNode(7);
    root->left->right->left = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    postOrderTraversal(root);

    delete(root);

    return 0;
}
