#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        // Basically brute force, for every element, pick either add it or don't add it an split into 2 paths
        vector<vector<int>> res;
        vector<int> curSubet;
        dfs(nums, 0, curSubet, res);
        return res;
    }

    // dfs on the decision tree
    void dfs(vector<int> &nums, int index, vector<int> &curSubset, vector<vector<int>> &res)
    {
        if (index >= nums.size())
        {
            // We make a deep copy
            res.push_back(curSubset);
            return;
        }

        // The number we are making a decision on
        int num = nums[index];

        // Decision 1: Don't include
        dfs(nums, index + 1, curSubset, res);

        // Decision 2: Include
        curSubset.push_back(num);
        dfs(nums, index + 1, curSubset, res);
        // Pop back for parent
        curSubset.pop_back();
    }
};
