#include <unordered_map>
#include <string>

using namespace std;

bool hasSubstr(unordered_map<char, int> s, unordered_map<char, int> t)
{
    for (auto &pair : t)
    {
        if (s.find(pair.first) == s.end())
        {
            return false;
        }
        if (s[pair.first] < pair.second)
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
        unordered_map<char, int> tMap;
        for (auto c : t)
        {
            tMap[c]++;
        }

        int n = s.size();
        int left = 0;
        int right = 0;
        string minS = "";
        unordered_map<char, int> sMap;
        while (right < n && !hasSubstr(sMap, tMap))
        {
            sMap[s[right]]++;
            right++;
        }

        while (right < n)
        {
            while (hasSubstr(sMap, tMap))
            {
                if (minS == "" || right - left < minS.size())
                {
                    minS = s.substr(left, right - left);
                }
                sMap[s[left]]--;
                left++;
            }
            sMap[s[right]]++;
            right++;
        }

        while (hasSubstr(sMap, tMap))
        {
            if (minS == "" || right - left < minS.size())
            {
                minS = s.substr(left, right - left);
            }
            sMap[s[left]]--;
            left++;
        }

        return minS;
    }
};
