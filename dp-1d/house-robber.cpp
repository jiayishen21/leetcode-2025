#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int rob1 = 0, rob2 = 0;
        for (int num : nums)
        {
            int tmp = max(rob1 + num, rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        return rob2;
    }

    int robInefficient(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }
        if (n == 2)
        {
            return max(nums[0], nums[1]);
        }
        if (n == 3)
        {
            return max(nums[0] + nums[2], nums[1]);
        }

        vector<int> maxSteal{nums[0], nums[1], max(nums[0] + nums[2], nums[1])};
        for (int i = 3; i < n; i++)
        {
            maxSteal.push_back(nums[i] + max(maxSteal[i - 2], maxSteal[i - 3]));
        }

        return max(maxSteal[n - 2], maxSteal[n - 1]);
    }
};
