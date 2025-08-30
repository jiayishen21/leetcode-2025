#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        for (int num : nums)
        {
            int idx = abs(num) - 1;
            if (nums[idx] < 0)
            {
                return abs(num);
            }
            nums[idx] *= -1;
        }
        return -1;
    }

    // This is not clean
    int findDuplicateBad(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == -1)
            {
                continue;
            }

            int j = i;
            int val;
            while (nums[j] != -1)
            {
                val = nums[j];
                int next = nums[j] - 1;
                nums[j] = -1;
                j = next;
            }

            // If we enter a cycle from a place other than the original entrance
            // The entrance is the duplicate
            if (j != i)
            {
                return val;
            }
        }

        return -1;
    }
};
