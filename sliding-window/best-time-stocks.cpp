#include <vector>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size();
        int buyP = prices[0];
        int maxP = 0;

        for (int right = 0; right < n; right++)
        {
            maxP = max(maxP, prices[right] - buyP);
            buyP = min(buyP, prices[right]);
        }

        return maxP;
    }
};
