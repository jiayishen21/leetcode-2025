#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
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

class Solution
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidHelper(root, false, 0, false, 0);
    }

    bool isValidHelper(TreeNode *t, bool minBounded, int minBound, bool maxBounded, int maxBound)
    {
        if (t == nullptr)
        {
            return true;
        }
        if (minBounded && t->val <= minBound)
        {
            return false;
        }
        if (maxBounded && t->val >= maxBound)
        {
            return false;
        }
        return isValidHelper(t->left, minBounded, minBound, true, t->val) && isValidHelper(t->right, true, t->val, maxBounded, maxBound);
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode{
        3,
        new TreeNode{1},
        new TreeNode{2}};
    bool success = s.isValidBST(root);
    cout << success << endl;
    delete root->left;
    delete root->right;
    delete root;
}