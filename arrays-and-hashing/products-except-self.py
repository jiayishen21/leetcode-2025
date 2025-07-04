class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = [1] * n
        suffix = [1] * n

        for i in range(n-1):
            prefix[i+1] = prefix[i] * nums[i]
            suffix[n-2-i] = suffix[n-1-i] * nums[n-1-i]

        res = []
        for i in range(n):
            res.append(prefix[i] * suffix[i])
        return res
