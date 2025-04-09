class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        if min(nums) < k:
            return -1
        elements = set(nums)
        if k in elements:
            elements.remove(k)
        return len(elements)