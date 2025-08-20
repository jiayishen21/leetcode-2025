#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        stack<int> leftIndex;
        stack<int> leftHeight;
        int maxA = 0;

        for (int i = 0; i < n; i++)
        {
            int recentIndex = i;
            while (!leftHeight.empty() && leftHeight.top() > heights[i])
            {
                maxA = max(maxA, (i - leftIndex.top()) * leftHeight.top());
                recentIndex = leftIndex.top();
                leftIndex.pop();
                leftHeight.pop();
            }

            leftIndex.push(recentIndex);
            leftHeight.push(heights[i]);
        }

        while (!leftIndex.empty())
        {
            maxA = max(maxA, (n - leftIndex.top()) * leftHeight.top());
            leftIndex.pop();
            leftHeight.pop();
        }
        return maxA;
    }
};
