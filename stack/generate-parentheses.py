from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        # All the solutions for n = i
        dp = [[] for _ in range(n+1)]

        dp[0] = [""]
        for m in range(1, n+1):
            # Every solution is (i) m-i

            for i in range(m):
                for left in dp[i]:
                    for right in dp[m-i-1]:
                        dp[m].append("("+left+")" + right)

        return dp[-1]
