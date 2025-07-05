from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid

            if nums[mid] > target:
                right = mid - 1
            else:
                left = mid + 1

        return -1

    def search2(self, nums: List[int], target: int) -> int:
        """
        Here's pseudo code

        int k = 0;
        for (int b = n/2; b >= 1; b /= 2) {
            while (k+b < n && array[k+b] <= x) {
                k += b;
            }
        }
        if (array[k] == x) {
            // x found at index k
        }
        """

        n = len(nums)
        i = 0
        increment = n // 2

        while increment >= 1:
            while i+increment < n and nums[i+increment] <= target:
                i += increment
            increment = increment // 2

        if nums[i] == target:
            return i
        return -1
