#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int replacementsNeeded(unordered_map<char, int> &umap)
{
    int charCount = 0;
    int maxCount = 0;
    for (auto &pair : umap)
    {
        charCount += pair.second;
        maxCount = max(maxCount, pair.second);
    }
    return charCount - maxCount;
}

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> freqs;
        int n = s.size();
        int left = 0;
        int right = 0;
        int maxL = 0;
        while (right < n)
        {
            if (freqs.find(s[right]) == freqs.end())
            {
                freqs[s[right]] = 0;
            }
            freqs[s[right]]++;
            right++;

            while (replacementsNeeded(freqs) > k)
            {
                freqs[s[left]]--;
                left++;
            }
            maxL = max(maxL, right - left);
        }
        return maxL;
    }
};
