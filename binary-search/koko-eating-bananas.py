from typing import List


# Whether we can eat all piles within h hours at a rate of k
def eatable(piles: List[int], h: int, k: int) -> int:
    timeTaken = 0
    for pile in piles:
        # Round up
        timeTaken += ((pile - 1) // k) + 1
    return timeTaken <= h


class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)
        lowest = right

        while left <= right:
            mid = (left+right) // 2
            if eatable(piles, h, mid):
                lowest = mid
                right = mid-1
            else:
                left = mid+1

        return lowest
