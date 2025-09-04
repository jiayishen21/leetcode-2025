#include <vector>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        int cost1 = cost[n - 1];
        int cost2 = cost[n - 2];
        for (int i = n - 3; i >= 0; i--)
        {
            int curCost = min(cost1, cost2) + cost[i];
            cost1 = cost2;
            cost2 = curCost;
        }
        return min(cost1, cost2);
    }
};
