#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int leftH = height[left];
        int rightH = height[right];
        int total = 0;

        while (left < right)
        {
            if (leftH < rightH)
            {
                left++;
                leftH = max(height[left], leftH);
                total += max(0, min(leftH, rightH) - height[left]);
            }
            else
            {
                right--;
                rightH = max(height[right], rightH);
                total += max(0, min(leftH, rightH) - height[right]);
            }
        }
        return total;
    }
};
