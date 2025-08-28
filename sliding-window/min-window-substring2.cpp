#include <unordered_map>
#include <string>

using namespace std;

bool hasSubstr(unordered_map<char, int> sFreqs, unordered_map<char, int> tFreqs)
{
    for (const auto &entry : tFreqs)
    {
        if (sFreqs.find(entry.first) == sFreqs.end())
        {
            return false;
        }
        if (sFreqs[entry.first] < entry.second)
        {
            return false;
        }
    }
    return true;
}

class Solution
{
public:
    string minWindow(string s, string t)
    {
        int n = s.length();
        unordered_map<char, int> tFreqs;

        for (const char c : t)
        {
            tFreqs[c]++;
        }

        unordered_map<char, int> sFreqs;
        string res = "";
        int left = 0;

        for (int right = 0; right < n; right++)
        {
            sFreqs[s[right]]++;
            while (hasSubstr(sFreqs, tFreqs))
            {
                if (res.length() == 0 || res.length() > right - left + 1)
                {
                    res = s.substr(left, right - left + 1);
                }
                sFreqs[s[left]]--;
                left++;
            }
        }
        return res;
    }
};
