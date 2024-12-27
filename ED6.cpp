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
    std::vector<int> preorderTraversal(TreeNode *root)
    {
        std::vector<int> result;
        if (!root)
            return result;
        std::stack<TreeNode *> stack;
        stack.push(root);
        while (!stack.empty())
        {
            TreeNode *node = stack.top();
            stack.pop();
            result.push_back(node->val);
            if (node->right)
                stack.push(node->right);
            if (node->left)
                stack.push(node->left);
        }
        return result;
    }
};
TreeNode *createTree()
{
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);
    return root;
}
int main()
{
    Solution solution;
    TreeNode *root = createTree();
    std::vector<int> result = solution.preorderTraversal(root);
    std::cout << "Preorder Traversal: ";
    for (int val : result)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return 0;
}