#include <vector>
#include <utility>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        if (nums2.size() < nums1.size())
        {
            swap(nums1, nums2);
        }

        int left = 0;
        int right = nums1.size() - 1;
    }
};
