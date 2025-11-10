#include <vector>
#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

    ~TreeNode()
    {
        delete left;
        delete right;
    }
};

class Solution
{
    int n;
    vector<int> preorder;
    vector<int> inorder;

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        n = preorder.size();
        this->preorder = preorder;
        this->inorder = inorder;
        return buildTreeHelper(0, n, 0, n);
    }

    TreeNode *buildTreeHelper(int pLeft, int pRight, int iLeft, int iRight)
    {
        if (pLeft >= pRight)
        {
            return nullptr;
        }

        int curVal = preorder[pLeft];
        TreeNode *t = new TreeNode{curVal};
        // Calculate where the left splits from the right
        int splitIndex = iLeft;
        while (splitIndex < iRight)
        {
            if (inorder[splitIndex] == curVal)
            {
                break;
            }
            splitIndex++;
        }
        int leftLength = splitIndex - iLeft;
        t->left = buildTreeHelper(pLeft + 1, pLeft + 1 + leftLength, iLeft, iLeft + leftLength);
        t->right = buildTreeHelper(pLeft + 1 + leftLength, pRight, splitIndex + 1, iRight);
        return t;
    }
};

int main()
{
    vector<int> preorder{1, 2, 3, 4, 5};
    vector<int> inorder{2, 3, 1, 4, 5};

    Solution s;
    TreeNode *t = s.buildTree(preorder, inorder);

    // Print tree layer by layer
    vector<TreeNode *> thisLayer{t};
    vector<TreeNode *> nextLayer;
    while (!thisLayer.empty())
    {
        TreeNode *cur = thisLayer[0];
        thisLayer.erase(thisLayer.begin());
        if (cur == nullptr)
        {
            cout << " N";
        }
        else
        {
            cout << " " << cur->val;
            nextLayer.push_back(cur->left);
            nextLayer.push_back(cur->right);
        }

        if (thisLayer.empty())
        {
            thisLayer = nextLayer;
            nextLayer.clear();
            cout << endl;
        }
    }
    delete t;
}