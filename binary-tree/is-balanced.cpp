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

// Return height if balanced, otherwise -1
int balancedHelper(TreeNode *cur)
{
    if (cur == nullptr)
        return 0;

    int leftH = balancedHelper(cur->left);
    int rightH = balancedHelper(cur->right);
    if (leftH == -1 || rightH == -1)
    {
        return -1;
    }
    if (abs(leftH - rightH) > 1)
    {
        return -1;
    }
    return max(leftH, rightH) + 1;
}

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        return balancedHelper(root) != -1;
    }
};
