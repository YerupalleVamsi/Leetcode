class Solution:
    def checkEqualPartitions(self, nums: List[int], target: int) -> bool:
        return math.prod(nums)==target*target
        