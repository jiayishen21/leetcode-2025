#include <algorithm>

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
    int goodNodes(TreeNode *root)
    {
        return 1 + goodNodesHelper(root->left, root->val) + goodNodesHelper(root->right, root->val);
    }

    int goodNodesHelper(TreeNode *cur, int curMax)
    {
        if (!cur)
            return 0;
        int curCounted = cur->val >= curMax ? 1 : 0;
        int newMax = max(cur->val, curMax);
        return curCounted + goodNodesHelper(cur->left, newMax) + goodNodesHelper(cur->right, newMax);
    }
};
