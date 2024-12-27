#include <iostream>
#include <vector>
#include <stack>
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                       right(right) {}
};
class Solution
{
public:
    int sumOfNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        return root->val + sumOfNodes(root->left) + sumOfNodes(root->right);
    }
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};
TreeNode *createTree()
{
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    return root;
}
void printTree(TreeNode *root)
{
    if (!root)
        return;
    printTree(root->left);
    std::cout << root->val << " ";
    printTree(root->right);
}
int main()
{
    Solution solution;
    TreeNode *root = createTree();
    std::cout << "Original tree (in-order): ";
    printTree(root);
    std::cout << std::endl;
    root = solution.invertTree(root);
    std::cout << "Inverted tree (in-order): ";
    printTree(root);
    std::cout << std::endl;
    return 0;
}