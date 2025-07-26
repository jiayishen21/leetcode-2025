from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        left = 0
        right = 1
        maxProfit = 0

        while right < n:
            if prices[left] < prices[right]:
                maxProfit = max(maxProfit, prices[right] - prices[left])
            else:
                left = right
            right += 1

        return maxProfit
