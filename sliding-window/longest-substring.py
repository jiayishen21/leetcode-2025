class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        n = len(s)
        left = 0
        right = 0
        curChars = set()
        maxLen = 0

        while right < n:
            if s[right] in curChars:
                maxLen = max(maxLen, right-left)
                while s[right] in curChars:
                    curChars.remove(s[left])
                    left += 1

            curChars.add(s[right])
            right += 1

        maxLen = max(maxLen, right-left)
        return maxLen
