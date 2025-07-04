SEPERATOR = ' '


class Solution:

    def encode(self, strs: List[str]) -> str:
        res = ''
        for s in strs:
            res += str(len(s)) + SEPERATOR + s

        return res

    def decode(self, s: str) -> List[str]:
        res = []
        i = 0
        while i < len(s):
            curLen = ''
            while s[i].isdigit():
                curLen += s[i]
                i += 1
            # Skip the seperator
            i += 1
            curLen = int(curLen)
            curStr = s[i:i+curLen]
            res.append(curStr)
            i += curLen

        return res
