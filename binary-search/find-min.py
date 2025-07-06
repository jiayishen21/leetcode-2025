from typing import List


class Solution:
    def findMin(self, nums: List[int]) -> int:
        # Already sorted
        if nums[0] < nums[-1]:
            return nums[0]

        left = 0
        right = len(nums)-1
        # For index i > 0,
        # If nums[i] > pivot, it's before the start of the array
        # If nums[i] < pivot, it's after the start of the array
        pivot = nums[0]

        while True:
            if right - left < 2:
                return min(nums[left], nums[right])

            mid = (left+right) // 2
            if nums[mid] > pivot:
                left = mid + 1
            else:
                right = mid
