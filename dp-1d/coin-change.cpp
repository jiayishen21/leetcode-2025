#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        unordered_map<int, int> dp;
        dp[0] = 0;
        return dfs(coins, amount, dp);
    }

    int dfs(vector<int> &coins, int amount, unordered_map<int, int> &dp)
    {
        if (dp.find(amount) != dp.end())
        {
            return dp[amount];
        }

        dp[amount] = -1;
        for (int c : coins)
        {
            if (c > amount)
            {
                continue;
            }
            int res = dfs(coins, amount - c, dp);
            if (res != -1 && (res < dp[amount] || dp[amount] == -1))
            {
                dp[amount] = res + 1;
            }
        }

        return dp[amount];
    }
};