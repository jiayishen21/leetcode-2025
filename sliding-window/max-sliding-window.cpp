#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<vector<int>> d;
        for (int i = 0; i < k; i++)
        {
            vector<int> v{nums[i], i};
            while (!d.empty() && nums[i] >= d.back()[0])
            {
                d.pop_back();
            }
            d.push_back(v);
        }

        vector<int> res(n - k + 1);
        res[0] = d.front()[0];

        for (int i = k; i < n; i++)
        {
            vector<int> v{nums[i], i};
            // pop outdated
            while (!d.empty() && i - k + 1 > d.front()[1])
            {
                d.pop_front();
            }

            // add new num
            while (!d.empty() && nums[i] >= d.back()[0])
            {
                d.pop_back();
            }
            d.push_back(v);

            res[i - k + 1] = d.front()[0];
        }
        return res;
    }
};
