from collections import defaultdict


def isSame(targetFreqs: dict[str, int], curFreqs: dict[str, int]) -> bool:
    for c in targetFreqs:
        if curFreqs[c] != targetFreqs[c]:
            return False

    return True


class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        n = len(s1)
        m = len(s2)
        if m < n:
            return False

        targetFreqs = defaultdict(int)
        curFreqs = defaultdict(int)

        for i in range(n):
            targetFreqs[s1[i]] += 1
            curFreqs[s2[i]] += 1

        if isSame(targetFreqs, curFreqs):
            return True

        for right in range(n, m):
            curFreqs[s2[right-n]] -= 1
            curFreqs[s2[right]] += 1

            if isSame(targetFreqs, curFreqs):
                return True

        return False
