
#include <utility>
#include <vector>

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

vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> res;
    if (root == nullptr)
    {
        return res;
    }
    vector<TreeNode *> curLevel;
    vector<TreeNode *> nextLevel{root};
    while (!nextLevel.empty())
    {
        curLevel = nextLevel;
        nextLevel.clear();

        res.push_back(vector<int>{});
        for (const auto &t : curLevel)
        {
            res.back().push_back(t->val);
            if (t->left != nullptr)
            {
                nextLevel.push_back(t->left);
            }
            if (t->right != nullptr)
            {
                nextLevel.push_back(t->right);
            }
        }
    }
    return res;
}

class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> res;
        dfs(root, 0, res);
        return res;
    }

    void dfs(TreeNode *t, int depth, vector<int> &res)
    {
        if (t == nullptr)
            return;

        if (res.size() == depth)
        {
            res.push_back(t->val);
        }
        dfs(t->right, depth + 1, res);
        dfs(t->left, depth + 1, res);
    }

    // Lazy solution using level order
    vector<int> rightSideViewLazy(TreeNode *root)
    {
        vector<vector<int>> levelView = levelOrder(root);
        vector<int> rightView;
        for (const auto &level : levelView)
        {
            rightView.push_back(level.back());
        }
        return rightView;
    }
};
