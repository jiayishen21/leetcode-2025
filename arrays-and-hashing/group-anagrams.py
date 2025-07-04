def hashStr(s: str) -> str:
    freq = {}
    for char in s:
        freq[char] = freq.get(char, 0) + 1

    hashed = ""
    sortedKeys = sorted(freq.keys())
    for char in sortedKeys:
        hashed += char + str(freq[char])
    return hashed


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        groups = {}
        for s in strs:
            hashed = hashStr(s)
            if groups.get(hashed):
                groups[hashed].append(s)
            else:
                groups[hashed] = [s]

        res = []
        for hashed in groups:
            res.append(groups[hashed])
        return res
