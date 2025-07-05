from typing import List


class Solution:
    def largestRectangleArea(self, heights: List[int]) -> int:
        n = len(heights)

        leftBound = [0] * n
        stack = []

        for i in range(n):
            while stack and heights[stack[-1]] > heights[i]:
                stack.pop()
            # Top of stack is now the first index j s.t. heights[j] <= heights[i]

            # No elements shorter than current element, bounded by 0
            if stack and heights[stack[-1]] == heights[i]:
                leftBound[i] = leftBound[stack[-1]]
            elif stack:
                leftBound[i] = stack[-1] + 1
            stack.append(i)

        rightBound = [n-1] * n
        stack = []

        for i in range(n-1, -1, -1):
            while stack and heights[stack[-1]] > heights[i]:
                stack.pop()
            # Top of stack is now the first index j s.t. heights[j] <= heights[i]

            # No elements shorter than current element, bounded by n-1
            if stack and heights[stack[-1]] == heights[i]:
                rightBound[i] = rightBound[stack[-1]]
            elif stack:
                rightBound[i] = stack[-1] - 1
            stack.append(i)

        print(leftBound)
        print(rightBound)

        maxArea = 0
        for i in range(n):
            area = (rightBound[i] - leftBound[i] + 1) * heights[i]
            maxArea = max(area, maxArea)

        return maxArea
