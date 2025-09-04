#include <vector>

using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return nums[0];
        }

        int rob1 = 0, rob2 = 0;
        // Attempt 1: Rob the first house
        for (int i = 0; i < n - 1; i++)
        {
            int tmp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = tmp;
        }
        int total1 = rob2;

        rob1 = 0;
        rob2 = 0;

        // Attempt 2: Skip the first house
        for (int i = 1; i < n; i++)
        {
            int tmp = max(rob1 + nums[i], rob2);
            rob1 = rob2;
            rob2 = tmp;
        }

        return max(total1, rob2);
    }
};
