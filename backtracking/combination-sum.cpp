#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> curSelected;
        dfs(nums, target, 0, res, curSelected);
        return res;
    }

    void dfs(vector<int> &nums, int missing, int index, vector<vector<int>> &res, vector<int> curSelected)
    {
        if (missing == 0)
        {
            res.push_back(curSelected);
            return;
        }
        if (index >= nums.size())
        {
            return;
        }

        int num = nums[index];
        if (num > missing)
        {
            // No way of succeeding
            return;
        }

        // Decision 1: Go to next number
        dfs(nums, missing, index + 1, res, curSelected);

        // Decision 2: Add another copy of cur number
        curSelected.push_back(num);
        dfs(nums, missing - num, index, res, curSelected);
        curSelected.pop_back();
    }
};
