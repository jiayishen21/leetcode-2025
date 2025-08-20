#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;

        sort(nums.begin(), nums.end());

        while (left <= right)
        {
            int mid = (left + right) / 2;
            cout << mid << endl;
            if (nums[mid] == target)
            {
                return mid;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        return -1;
    }
};
