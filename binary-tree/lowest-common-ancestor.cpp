#include <utility>

/**
 * Definition for a binary tree node.
 */
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

using namespace std;

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        int leftVal = min(p->val, q->val);
        int rightVal = max(p->val, q->val);

        while (true)
        {
            if (root->val >= leftVal && root->val <= rightVal)
            {
                return root;
            }
            if (root->val < leftVal)
            {
                root = root->right;
            }
            else
            {
                root = root->left;
            }
        }
    }
};
