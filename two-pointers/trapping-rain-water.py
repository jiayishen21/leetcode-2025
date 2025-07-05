
from typing import List


class Solution:
    # Optimal solution with two pointers, O(n) time and O(1) space
    def trap(self, height: List[int]) -> int:
        left = 0
        maxLeft = 0
        right = len(height) - 1
        maxRight = 0

        total = 0
        # We need at least 1 space between the 2 walls to have area
        while left < right - 1:
            maxLeft = max(height[left], maxLeft)
            maxRight = max(height[right], maxRight)

            if maxLeft < maxRight:
                total += max(0, maxLeft - height[left+1])
                left += 1
            else:
                total += max(0, maxRight - height[right-1])
                right -= 1

        return total

    # Suboptimal with prefix and suffix, O(n) time but O(n) space
    def trapPrefixSuffix(self, height: List[int]) -> int:
        n = len(height)
        maxBefore = [0] * n
        maxBefore[0] = height[0]

        maxAfter = [0] * n
        maxAfter[n-1] = height[n-1]

        for i in range(1, n):
            maxBefore[i] = max(height[i], maxBefore[i-1])
            maxAfter[n-1-i] = max(height[n-1-i], maxAfter[n-i])

        total = 0
        for i in range(n):
            if height[i] < min(maxBefore[i], maxAfter[i]):
                total += min(maxBefore[i], maxAfter[i]) - height[i]

        return total
