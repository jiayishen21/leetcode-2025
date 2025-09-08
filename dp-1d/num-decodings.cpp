#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size();

        // We only ever access dp[i+1] and dp[i+2] so we don't need O(n) space
        // and can optimize by just storing 2 variables denoting those values
        vector<int> dp(n + 1, 0);
        dp[n] = 1;
        if (s[n - 1] > '0')
        {
            dp[n - 1] = 1;
        }

        for (int i = n - 2; i >= 0; i--)
        {
            if (s[i] == '0')
            {
                continue;
            }
            if (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6'))
            {
                dp[i] = dp[i + 1] + dp[i + 2];
            }
            else
            {
                dp[i] = dp[i + 1];
            }
        }

        cout << endl;
        return dp[0];
    }
};
