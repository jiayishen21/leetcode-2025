#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        int n = nums.size();
        int i = 0;

        while (i < n)
        {
            int num = nums[i] - 1;
            if (num < 0 || num >= n || i == num)
            {
                i++;
                continue;
            }
            int tmp = nums[num];
            // Avoid duplicates
            if (tmp == num + 1)
            {
                i++;
                continue;
            }
            nums[num] = num + 1;
            nums[i] = tmp;
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i + 1)
            {
                return i + 1;
            }
        }
        return n + 1;
    }
};