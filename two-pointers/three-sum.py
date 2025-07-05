from typing import List


class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        # Think about sorting with array questions when goal is > O(n logn)
        nums.sort()

        i = 0
        n = len(nums)
        res = []

        while i < n - 2 and nums[i] <= 0:
            if i > 0 and nums[i] == nums[i-1]:
                i += 1
                continue

            target = -nums[i]

            # 2 sum
            left = i + 1
            right = n - 1
            pairs = []
            while left < right:
                if left > i + 1 and nums[left] == nums[left-1]:
                    left += 1
                    continue

                if nums[left] + nums[right] == target:
                    pairs.append([nums[left], nums[right]])
                    left += 1
                    right -= 1
                elif nums[left] + nums[right] > target:
                    right -= 1
                else:
                    left += 1

            for pair in pairs:
                res.append([nums[i], pair[0], pair[1]])
            i += 1

        return res
