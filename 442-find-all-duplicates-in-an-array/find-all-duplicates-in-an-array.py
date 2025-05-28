class Solution:
    def findDuplicates(self, nums: list[int]) -> list[int]:
        seen = set()
        res = set()
        for num in nums:
            if num in seen:
                res.add(num)
            else:
                seen.add(num)
        return list(res)
