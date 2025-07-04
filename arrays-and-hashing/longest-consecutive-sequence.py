class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        numSet = set(nums)

        longest = 0
        for num in nums:
            if num not in numSet:
                continue
            counter = 1
            numSet.remove(num)
            left = num - 1
            while left in numSet:
                counter += 1
                numSet.remove(left)
                left -= 1

            right = num + 1
            while right in numSet:
                counter += 1
                numSet.remove(right)
                right += 1

            longest = max(counter, longest)

        return longest
