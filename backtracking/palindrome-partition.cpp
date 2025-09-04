#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<string>> res;

    vector<vector<string>> partition(string s)
    {
        vector<string> cur;
        string next = "";
        dfs(s, 0, cur, next);
        return res;
    }

    bool isPali(string &next)
    {
        int n = next.size();
        for (int i = 0; i < n / 2; i++)
        {
            if (next[i] != next[n - 1 - i])
            {
                return false;
            }
        }
        cout << next << endl;
        return true;
    }

    void dfs(string &s, int index, vector<string> &cur, string &next)
    {
        if (index >= s.size() && next.size() == 0)
        {
            res.push_back(cur);
            return;
        }

        if (next.size() && isPali(next))
        {
            cur.push_back(next);
            string newNext = "";
            dfs(s, index, cur, newNext);
            cur.pop_back();
        }

        if (index < s.size())
        {
            next += s[index];
            dfs(s, index + 1, cur, next);
        }
    }
};
