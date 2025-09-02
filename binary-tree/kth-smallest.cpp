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
    int res;

public:
    int getSize(TreeNode *t, int smaller, int k)
    {
        if (!t)
            return 0;

        int leftSz = getSize(t->left, smaller, k);
        smaller += leftSz;
        if (smaller + 1 == k)
        {
            res = t->val;
        }
        int sz = leftSz + 1 + getSize(t->right, smaller + 1, k);
        return sz;
    }

    int kthSmallest(TreeNode *root, int k)
    {
        getSize(root, 0, k);
        return res;
    }
};
