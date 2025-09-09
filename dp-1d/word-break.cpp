#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size(); 
        vector<bool> dp(n+1, false);
        dp[n] = true;

        for(int i = n-1; i >= 0; i--) {
            for(string &w : wordDict) {
                if (n-i < w.size()) {
                    continue;
                }
                if (s.substr(i, w.size()) == w && dp[i+w.size()]) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
