#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<int> uniqueNums;
        unordered_map<int, int> freqs;

        for (int num : nums)
        {
            if (freqs.find(num) == freqs.end())
            {
                uniqueNums.push_back(num);
            }
            freqs[num]++;
        }
        vector<vector<int>> res;
        vector<int> selected;

        backtrack(uniqueNums, freqs, 0, res, selected);
        return res;
    }

    void backtrack(vector<int> &nums, unordered_map<int, int> &freqs, int index, vector<vector<int>> &res, vector<int> &selected)
    {
        if (index >= nums.size())
        {
            res.push_back(selected);
            return;
        }

        // Decision 1: Go next
        backtrack(nums, freqs, index + 1, res, selected);

        // Decision 2: Include
        int num = nums[index];
        if (freqs[num])
        {
            freqs[num]--;
            selected.push_back(num);
            backtrack(nums, freqs, index, res, selected);
            freqs[num]++;
            selected.pop_back();
        }
    }
};
