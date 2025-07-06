from typing import Dict


class TimeMap:
    actualMap: Dict

    def __init__(self):
        self.actualMap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if key in self.actualMap:
            self.actualMap[key].append([value, timestamp])
        else:
            self.actualMap[key] = [[value, timestamp]]

    def get(self, key: str, timestamp: int) -> str:
        if key not in self.actualMap:
            return ""

        vals = self.actualMap[key]
        if vals[0][1] > timestamp:
            return ""

        left = 0
        right = len(vals)-1
        mostRecent = left

        while left <= right:
            mid = (left+right)//2
            if vals[mid][1] == timestamp:
                return vals[mid][0]
            elif vals[mid][1] < timestamp:
                mostRecent = mid
                left = mid+1
            else:
                right = mid-1
        return vals[mostRecent][0]
