from collections import defaultdict


# O(1) since finite chars
def maxFreq(charFreqs: dict[str, int]):
    maxFreq = 0
    for c in charFreqs:
        if charFreqs[c] > maxFreq:
            maxFreq = charFreqs[c]

    return maxFreq


class Solution:

    def characterReplacement(self, s: str, k: int) -> int:
        n = len(s)
        left = 0
        right = 0
        charFreqs = defaultdict(int)
        maxLen = 0

        while right < n:
            charFreqs[s[right]] += 1
            right += 1

            while right-left-maxFreq(charFreqs) > k:
                charFreqs[s[left]] -= 1
                left += 1

            print(right, left)
            maxLen = max(maxLen, right-left)

        return maxLen
