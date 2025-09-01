#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        // Let there be a cycle of size c
        // Let it take d steps to get into the cycle from index 0
        // Let the cycle be split into lengths of x and y based on where the fast and slow pointer met

        // Fast = Slow (mod c)
        // 2(d+y) = d+y (mod c)
        // d+y = 0 (mod c)
        // d+y = 0 (mod x+y)
        // d+y = x+y (mod x+y)
        // d = x (mod c), 0 >= x < c

        int slow = 0;
        int fast = 0;
        while (true)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
            if (slow == fast)
            {
                break;
            }
        }

        int slow2 = 0;
        while (true)
        {
            slow = nums[slow];
            slow2 = nums[slow2];
            if (slow == slow2)
            {
                break;
            }
        }
        return slow2;
    }
};
