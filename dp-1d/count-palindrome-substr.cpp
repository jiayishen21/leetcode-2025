#include <string>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        int total = 0;
        int n = s.size();

        // Odd-sized
        for (int i = 0; i < n; i++)
        {
            // Let the palindrome be centered at i
            int j = 0;
            while (i - j >= 0 && i + j < n)
            {
                if (s[i - j] != s[i + j])
                {
                    break;
                }
                total++;
                j++;
            }
        }

        // Even-sized
        for (int i = 0; i < n; i++)
        {
            // Let the palindrome be centered at i
            int j = 0;
            while (i - j >= 0 && i + 1 + j < n)
            {
                if (s[i - j] != s[i + 1 + j])
                {
                    break;
                }
                total++;
                j++;
            }
        }

        return total;
    }
};
