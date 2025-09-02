#include <vector>
#include <unordered_map>
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

// Returns pair of tree, rightmost preorderIndex that we actually used
pair<TreeNode *, int> buildTreeHelper(vector<int> &preorder, unordered_map<int, int> inMap, int preorderIndex, int maxInorderIndex)
{
    if (preorderIndex >= preorder.size())
    {
        return pair<TreeNode *, int>{nullptr, 0};
    }
    int val = preorder[preorderIndex];
    int inorderIndex = inMap[val];
    if (inorderIndex >= maxInorderIndex)
    {
        return pair<TreeNode *, int>{nullptr, 0};
    }
    TreeNode *res = new TreeNode(val);
    pair<TreeNode *, int> leftRes = buildTreeHelper(preorder, inMap, preorderIndex + 1, inorderIndex);
    res->left = leftRes.first;
    preorderIndex = max(preorderIndex, leftRes.second);
    pair<TreeNode *, int> rightRes = buildTreeHelper(preorder, inMap, preorderIndex + 1, maxInorderIndex);
    res->right = rightRes.first;
    preorderIndex = max(preorderIndex, rightRes.second);

    return pair<TreeNode *, int>{res, preorderIndex};
}

class Solution
{
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int n = preorder.size();
        unordered_map<int, int> inMap;

        for (int i = 0; i < n; i++)
        {
            inMap[inorder[i]] = i;
        }

        return buildTreeHelper(preorder, inMap, 0, n).first;
    }
};
