from typing import List


class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        stack = []
        for token in tokens:
            print(stack)
            if token.isnumeric():
                stack.append(int(token))
                continue
            if len(token) > 1 and token[0] == '-':
                stack.append(-int(token[1:]))
                continue

            right = int(stack.pop())
            left = int(stack.pop())

            if token == '+':
                stack.append(left + right)
            elif token == '-':
                stack.append(left - right)
            elif token == '*':
                stack.append(left * right)
            else:
                sign = 1
                if (left < 0 and right > 0) or (left > 0 and right < 0):
                    sign = -1
                val = abs(left) // abs(right)
                stack.append(sign * val)

        return stack[0]
