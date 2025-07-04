class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        numMap = {}

        for i in range(len(nums)):
            num = nums[i]
            if num * 2 == target and num in numMap:
                return [numMap[num], i]
            numMap[num] = i

        for i in range(len(nums)):
            num = nums[i]
            conj = target - num
            if num * 2 == target:
                continue
            if conj in numMap:
                return [i, numMap[conj]]

        # Should not happen
        return []
