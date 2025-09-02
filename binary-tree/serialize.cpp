#include <string>
#include <utility>
#include <iostream>
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

void serializeHelper(TreeNode *t, string &res, bool isRight)
{
    if (!t)
    {
        if (isRight)
        {
            res += "R";
        }
        else
        {
            res += "L";
        }
    }
    else
    {
        res += t->val + '0';
        if (isRight)
        {
            res += "r";
        }
        else
        {
            res += "l";
        }
        serializeHelper(t->left, res, false);
        serializeHelper(t->right, res, true);
    }
}

class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
        {
            return "";
        }
        string res = "";
        serializeHelper(root, res, true);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data == "")
        {
            return nullptr;
        }
        vector<TreeNode *> curPath;
        TreeNode *res = nullptr;
        int curVal = 0;
        for (char c : data)
        {
            if (c == 'L')
            {
                // Last node already has left null
                continue;
            }
            if (c == 'R')
            {
                // Last node already has right null, just pop now that we're done with it
                if (curPath.empty())
                {
                    return nullptr;
                }
                curPath.pop_back();
                continue;
            }

            if (c == 'r' || c == 'l')
            {
                TreeNode *newNode = new TreeNode(curVal);
                curVal = 0;

                if (!res)
                {
                    res = newNode;
                }
                else if (c == 'l')
                {
                    if (curPath.empty())
                    {
                        return nullptr;
                    }
                    curPath.back()->left = newNode;
                }
                else if (c == 'r')
                {
                    if (curPath.empty())
                    {
                        return nullptr;
                    }
                    curPath.back()->right = newNode;
                    curPath.pop_back();
                }
                curPath.push_back(newNode);
                continue;
            }

            // Handle integer
            curVal *= 10;
            curVal += c - '0';
        }

        return res;
    }
};
