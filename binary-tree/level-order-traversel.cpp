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

class Solution
{
public:
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
};
