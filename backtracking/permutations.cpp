#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> selected;
        set<int> remaining;
        for (int num : nums)
        {
            remaining.insert(num);
        }

        backtrack(remaining, selected, res);
        return res;
    }

    void backtrack(set<int> &remaining, vector<int> &selected, vector<vector<int>> &res)
    {
        if (remaining.empty())
        {
            res.push_back(selected);
            return;
        }

        vector<int> keys;
        for (int key : remaining)
        {
            keys.push_back(key);
        }

        for (int key : keys)
        {
            remaining.erase(key);
            selected.push_back(key);
            backtrack(remaining, selected, res);
            remaining.insert(key);
            selected.pop_back();
        }
    }
};
