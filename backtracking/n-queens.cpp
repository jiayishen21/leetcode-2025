#include <vector>
#include <string>
#include <set>

using namespace std;

class Solution
{
public:
    int n;
    vector<vector<string>> res;
    set<int> hor;
    set<int> vert;
    set<int> diag1;
    set<int> diag2;

    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;
        vector<string> cur;
        dfs(cur, 0, 0, 0);
        return res;
    }

    void dfs(vector<string> &cur, int curQueens, int i, int j)
    {
        if (j >= n)
        {
            i++;
            j = 0;
        }
        if (i >= n)
        {
            if (curQueens == n)
            {
                res.push_back(cur);
            }
            return;
        }

        if (cur.empty() || cur.back().size() == n)
        {
            cur.push_back("");
        }

        // Option 1: No queen here
        cur.back() += '.';
        dfs(cur, curQueens, i, j + 1);
        cur.back().pop_back();

        // Option 2: Add queen
        if (curQueens < n && !hor.count(i) && !vert.count(j) && !diag1.count(i - j) && !diag2.count(n - 1 - i - j))
        {
            hor.insert(i);
            vert.insert(j);
            diag1.insert(i - j);
            diag2.insert(n - 1 - i - j);
            cur.back() += 'Q';

            dfs(cur, curQueens + 1, i, j + 1);

            cur.back().pop_back();
            hor.erase(i);
            vert.erase(j);
            diag1.erase(i - j);
            diag2.erase(n - 1 - i - j);
        }

        if (cur.back().size() == 0)
        {
            cur.pop_back();
        }
    }
};
