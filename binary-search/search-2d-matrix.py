from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])
        left = 0
        right = n-1

        targetRow = -1

        while left <= right:
            mid = (left + right) // 2

            if matrix[mid][0] <= target and matrix[mid][-1] >= target:
                targetRow = mid
                break
            elif matrix[mid][0] > target:
                right = mid - 1
            else:
                left = mid + 1

        if targetRow == -1:
            return False

        left = 0
        right = m-1
        nums = matrix[targetRow]
        while left <= right:
            mid = (left+right) // 2
            if nums[mid] == target:
                return True
            if nums[mid] > target:
                right = mid-1
            else:
                left = mid+1
        return False
