class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        j=2
        for i in range(2,len(nums)):
            if nums[j-2]!=nums[i]:
                nums[j]=nums[i]
                j+=1
        return j
        