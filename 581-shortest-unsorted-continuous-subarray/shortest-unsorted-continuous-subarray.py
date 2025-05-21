class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        sortednums=sorted(nums)
        end=0
        start=len(nums)
        for i in range(len(nums)):
            if nums[i]!=sortednums[i]:
                start=min(start,i)
                end=max(end,i)
        return end-start+1 if end>start else 0

        