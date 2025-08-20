#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_map<int, int> chainLen;
        int maxLen = 0;

        for (auto num : nums)
        {
            if (chainLen.find(num) != chainLen.end())
            {
                continue;
            }

            int left = 0;
            int right = 0;
            if (chainLen.find(num - 1) != chainLen.end())
            {
                left = chainLen[num - 1];
            }
            if (chainLen.find(num + 1) != chainLen.end())
            {
                right = chainLen[num + 1];
            }
            chainLen[num] = 1 + left + right;
            maxLen = max(chainLen[num], maxLen);
            chainLen[num - left] = chainLen[num];
            chainLen[num + right] = chainLen[num];
        }

        return maxLen;
    }
};
