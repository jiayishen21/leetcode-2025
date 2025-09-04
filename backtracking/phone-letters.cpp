#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    vector<string> m{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> res;

    vector<string> letterCombinations(string digits)
    {
        if (digits.size() == 0)
        {
            return res;
        }
        string cur = "";
        backtrack(digits, cur);
        return res;
    }

    void backtrack(string &digits, string &cur)
    {
        int index = cur.size();
        if (index == digits.size())
        {
            res.push_back(cur);
            return;
        }

        int digit = digits[index] - '0';
        for (char c : m[digit])
        {
            cur += c;
            backtrack(digits, cur);
            cur.pop_back();
        }
    }
};
