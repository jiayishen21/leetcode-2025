#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
            {
                return res;
            }
            if (i > 0 && nums[i - 1] == nums[i])
            {
                continue;
            }

            // Do a sorted 2sum on this
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            while (left < right)
            {
                if (left > i + 1 && nums[left] == nums[left - 1])
                {
                    left++;
                    continue;
                }

                if (nums[left] + nums[right] == target)
                {
                    res.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    left++;
                }
                else if (nums[left] + nums[right] < target)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }

        return res;
    }
};
