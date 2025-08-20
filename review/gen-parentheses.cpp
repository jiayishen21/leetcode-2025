#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> generateParenthesis(int n)
    {
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");

        for (int i = 1; i < n + 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                vector<string> &left = dp[j];
                vector<string> &right = dp[i - 1 - j];

                for (const auto &x : left)
                {
                    for (const auto &y : right)
                    {
                        dp[i].push_back("(" + x + ")" + y);
                    }
                }
            }
        }

        return dp[n];
    }
};
