#include <utility>
#include <iostream>

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
    bool isValidBST(TreeNode *root)
    {
        return isValidBSTHelper(root, 0, 0, false, false);
    }

    bool isValidBSTHelper(TreeNode *cur, int minVal, int maxVal, bool minBounded, bool maxBounded)
    {
        if (!cur)
            return true;

        if (minBounded && cur->val <= minVal)
        {
            return false;
        }
        if (maxBounded && cur->val >= maxVal)
        {
            return false;
        }

        if (!minBounded)
        {
            minVal = cur->val;
        }

        if (!maxBounded)
        {
            maxVal = cur->val;
        }

        return isValidBSTHelper(cur->left, minVal, min(maxVal, cur->val), minBounded, true) &&
               isValidBSTHelper(cur->right, max(minVal, cur->val), maxVal, true, maxBounded);
    }
};
