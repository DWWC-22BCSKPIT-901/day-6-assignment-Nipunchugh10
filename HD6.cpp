#include <iostream>
using namespace std;
struct Node
{
    int val;
    Node *left;
    Node *right;
    Node *next;
    Node(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};
class Solution
{
public:
    void connect(Node *root)
    {
        if (root == NULL)
        {
            return;
        }
        Node *current = root;
        while (current != NULL)
        {
            Node *levelStart = current;
            Node *prev = NULL;
            while (levelStart != NULL)
            {
                if (levelStart->left)
                {
                    if (prev)
                    {
                        prev->next = levelStart->left;
                    }
                    prev = levelStart->left;
                }
                if (levelStart->right)
                {
                    if (prev)
                    {
                        prev->next = levelStart->right;
                    }
                    prev = levelStart->right;
                }
                levelStart = levelStart->next;
            }
            current = current->left;
        }
    }
};
void printLevels(Node *root)
{
    while (root)
    {
        Node *current = root;
        while (current)
        {
            cout << current->val << " ";
            current = current->next;
        }
        cout << "# ";
        root = root->left;
    }
    cout << endl;
}
int main()
{
    // Example: root = [1,2,3,4,5,null,7]
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(7);
    Solution solution;
    solution.connect(root);
    printLevels(root);
    return 0;
}