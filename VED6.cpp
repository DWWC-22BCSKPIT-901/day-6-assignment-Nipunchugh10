#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void inorderRecursive(TreeNode *root, vector<int> &result)
{
    if (root == NULL)
        return;
    inorderRecursive(root->left, result);
    result.push_back(root->val);
    inorderRecursive(root->right, result);
}
vector<int> inorderIterative(TreeNode *root)
{
    vector<int> result;
    stack<TreeNode *> stack;
    TreeNode *current = root;
    while (current != NULL || !stack.empty())
    {
        while (current != NULL)
        {
            stack.push(current);
            current = current->left;
        }
        current = stack.top();
        stack.pop();
        result.push_back(current->val);
        current = current->right;
    }
    return result;
}
void printVector(const vector<int> &vec)
{
    for (int val : vec)
    {
        cout << val << " ";
    }
    cout << endl;
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    vector<int> resultRecursive;
    inorderRecursive(root, resultRecursive);
    cout << "Recursive Inorder Traversal: ";
    printVector(resultRecursive);
    vector<int> resultIterative = inorderIterative(root);
    cout << "Iterative Inorder Traversal: ";
    printVector(resultIterative);
    return 0;
}