#include <algorithm>
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

pair<int, int> diameterHelper(TreeNode *cur)
{
    if (cur == nullptr)
    {
        return pair<int, int>{0, 0};
    }

    pair<int, int> leftRes = diameterHelper(cur->left);
    pair<int, int> rightRes = diameterHelper(cur->right);

    int depth = max(leftRes.first, rightRes.first) + 1;
    int diameter = max(leftRes.second, rightRes.second);
    diameter = max(diameter, leftRes.first + rightRes.first);
    return pair<int, int>{depth, diameter};
}

class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        return diameterHelper(root).second;
    }
};
