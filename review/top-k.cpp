#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        unordered_map<int, int> freqs;

        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (freqs.find(num) == freqs.end())
            {
                freqs[num] = 0;
            }
            freqs[num]++;
        }

        vector<vector<int>> buckets(n + 1);

        for (const auto &[num, freq] : freqs)
        {
            buckets[freq].push_back(num);
        }

        vector<int> res(k);
        int counter = 0;
        for (int i = n; i >= 0; i--)
        {
            for (auto num : buckets[i])
            {
                res[counter] = num;
                counter++;

                if (counter >= k)
                {
                    return res;
                }
            }
        }
        return res;
    }
};
