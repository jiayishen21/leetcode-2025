#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestPalindrome(string s)
    {
        int n = s.size();
        string res = "";

        // Loop 1: Odd-length
        for (int i = 0; i < n; i++)
        {
            // Let i be the center of the palindrome
            int j = 0;
            while (i - j >= 0 && i + j < n)
            {
                if (s[i - j] != s[i + j])
                {
                    break;
                }

                int newSz = 1 + 2 * j;
                if (newSz > res.size())
                {
                    res = s.substr(i - j, newSz);
                }
                j++;
            }
        }

        // Loop 2: Even-length
        for (int i = 0; i < n - 1; i++)
        {
            // Let i,i+1 be the center of the palindrome
            int j = 0;
            while (i - j >= 0 && i + 1 + j < n)
            {
                if (s[i - j] != s[i + 1 + j])
                {
                    break;
                }

                int newSz = 2 + 2 * j;
                if (newSz > res.size())
                {
                    res = s.substr(i - j, newSz);
                }
                j++;
            }
        }
        return res;
    }
};
