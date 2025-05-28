class Solution:
    def findDuplicates(self, nums: List[int]) -> List[int]:
        if len(nums)<=1:
            return []
        res=[]
        nums.sort()
        for i in range(1,len(nums)):
            if(nums[i]==nums[i-1]):
                res.append(nums[i])
        res=set(res)
        res=list(res)
        return res