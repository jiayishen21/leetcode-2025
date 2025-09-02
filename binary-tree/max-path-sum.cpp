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

int findLargest(TreeNode *t)
{
    int largestLeft = t->left ? findLargest(t->left) : t->val;
    int largestRight = t->right ? findLargest(t->right) : t->val;

    return max(t->val, max(largestLeft, largestRight));
}

// Returns maxPathSum, maxPath going through current node
pair<int, int> maxPathSumHelper(TreeNode *t)
{
    if (!t)
    {
        return pair<int, int>{0, 0};
    }

    pair<int, int> leftRes = maxPathSumHelper(t->left);
    pair<int, int> rightRes = maxPathSumHelper(t->right);
    int maxPathSum = max(leftRes.first, rightRes.first);
    maxPathSum = max(maxPathSum, t->val + leftRes.second + rightRes.second);

    int maxPathThrough = max(t->val + leftRes.second, t->val + rightRes.second);
    maxPathThrough = max(0, maxPathThrough);

    return pair<int, int>{maxPathSum, maxPathThrough};
}

class Solution
{
public:
    int maxPathSum(TreeNode *root)
    {
        int largest = findLargest(root);
        if (largest <= 0)
        {
            return largest;
        }
        return maxPathSumHelper(root).first;
    }
};
