#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int maxPos = 0;
        int maxMin = 0;
        for(int num : nums) {
            if (num == 0) {
                maxPos = 0;
                maxMin = 0;
                res = max(0, res);
                continue;
            }

            if (num > 0) {
                int newMin = maxMin * num;
                maxPos = max(num, maxPos * num);
                maxMin = newMin;
            }
            else {
                int newPos = maxMin * num;
                maxMin = min(num, maxPos * num);
                maxPos = newPos;
            }

            if (maxPos) {
                res = max(res, maxPos);
            }
        }
        return res;
    }
};
