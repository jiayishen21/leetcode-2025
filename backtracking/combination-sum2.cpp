#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<int> uniqueCandidates;
        unordered_map<int, int> candidateFreqs;
        for (int cand : candidates)
        {
            if (candidateFreqs.find(cand) == candidateFreqs.end())
            {
                uniqueCandidates.push_back(cand);
            }
            candidateFreqs[cand]++;
        }

        vector<vector<int>> res;
        vector<int> curSelected;

        backtrack(uniqueCandidates, candidateFreqs, target, 0, res, curSelected);
        return res;
    }

    void backtrack(vector<int> &candidates, unordered_map<int, int> candidateFreqs, int missing, int index, vector<vector<int>> &res, vector<int> &curSelected)
    {
        if (missing == 0)
        {
            res.push_back(curSelected);
            return;
        }
        if (index >= candidates.size() || missing < 0)
        {
            return;
        }

        int num = candidates[index];

        // Decision 1: Skip
        backtrack(candidates, candidateFreqs, missing, index + 1, res, curSelected);

        // Decision 2: Include
        if (candidateFreqs[num])
        {
            candidateFreqs[num]--;
            curSelected.push_back(num);
            backtrack(candidates, candidateFreqs, missing - num, index, res, curSelected);
            candidateFreqs[num]++;
            curSelected.pop_back();
        }
    }
};
