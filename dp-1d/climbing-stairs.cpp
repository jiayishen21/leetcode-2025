#include <vector>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        // Solvable in O(1) with combinatorics i think, but here's the dp solution

        // This could be done without the dp array too since we only need the last 2
        vector<int> dp{0, 1, 2};
        for (int i = 3; i <= n; i++)
        {
            dp.push_back(dp[i - 1] + dp[i - 2]);
        }
        return dp[n];
    }
};
