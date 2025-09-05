#include <vector>
#include <deque>

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> d;
        vector<int> res;

        // Initialize the first window
        for (int i = 0; i < k; i++)
        {
            while (!d.empty() && nums[d.back()] < nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
        }
        res.push_back(nums[d.front()]);

        for (int i = k; i < n; i++)
        {
            while (!d.empty() && d.front() <= i - k)
            {
                d.pop_front();
            }
            while (!d.empty() && nums[d.back()] < nums[i])
            {
                d.pop_back();
            }
            d.push_back(i);
            res.push_back(nums[d.front()]);
        }

        return res;
    }
};