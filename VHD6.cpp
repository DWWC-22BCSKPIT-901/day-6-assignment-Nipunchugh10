#include <iostream>
#include <queue>
#include <vector>
#include <deque>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(Node *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }
        queue<Node *> q;
        q.push(root);
        bool leftToRight = true;
        while (!q.empty())
        {
            int levelSize = q.size();
            deque<int> currentLevel;
            for (int i = 0; i < levelSize; ++i)
            {
                Node *currentNode = q.front();
                q.pop();
                if (leftToRight)
                {
                    currentLevel.push_back(currentNode->val);
                }
                else
                {
                    currentLevel.push_front(currentNode->val);
                }
                if (currentNode->left)
                {
                    q.push(currentNode->left);
                }
                if (currentNode->right)
                {
                    q.push(currentNode->right);
                }
            }
            result.push_back(vector<int>(currentLevel.begin(),
                                         currentLevel.end()));
            leftToRight = !leftToRight;
        }
        return result;
    }
};
void printZigzagOrder(const vector<vector<int>> &zigzagOrder)
{
    for (const auto &level : zigzagOrder)
    {
        for (int val : level)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
int main()
{
    // Example: root = [3,9,20,null,null,15,7]
    Node *root = new Node(3);
    root->left = new Node(9);
    root->right = new Node(20);
    root->right->left = new Node(15);
    root->right->right = new Node(7);
    Solution solution;
    vector<vector<int>> zigzagOrder = solution.zigzagLevelOrder(root);
    printZigzagOrder(zigzagOrder);
    return 0;
}