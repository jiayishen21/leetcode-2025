class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        # Really smart bucket sort
        n = len(nums)
        freq = {}
        for num in nums:
            freq[num] = freq.get(num, 0) + 1

        buckets = [[] for _ in range(n+1)]
        for num in freq:
            buckets[freq[num]].append(num)

        res = [0] * k
        counter = 0
        for bucket in reversed(buckets):
            if counter >= k:
                return res
            for i in range(len(bucket)):
                res[counter + i] = bucket[i]
            counter += len(bucket)

        return []
