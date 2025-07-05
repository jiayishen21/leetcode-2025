from typing import List


class MinStack:
    actualStack: List[int]
    minIndex: List[int]

    def __init__(self):
        self.actualStack = []
        self.minIndex = []

    def push(self, val: int) -> None:
        self.actualStack.append(val)
        if len(self.minIndex) == 0:
            self.minIndex.append(0)
        # New min
        elif val < self.actualStack[self.minIndex[-1]]:
            self.minIndex.append(len(self.minIndex))
        else:
            self.minIndex.append(self.minIndex[-1])

    def pop(self) -> None:
        self.actualStack.pop()
        self.minIndex.pop()

    def top(self) -> int:
        return self.actualStack[-1]

    def getMin(self) -> int:
        return self.actualStack[self.minIndex[-1]]
