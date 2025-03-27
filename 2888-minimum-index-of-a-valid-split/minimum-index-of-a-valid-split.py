class Solution:
    def minimumIndex(self, nums: List[int]) -> int:
        major=None
        count=0
        for num in nums:
            if count==0:
                major=num
            count+=(1 if num == major else -1)
        totalcount=nums.count(major)    
        if totalcount<=len(nums)//2:
            return -1
        dominant=major
        leftcount=0
        for i in range(len(nums)):
            if nums[i]==dominant:
                leftcount+=1
            rightcount=totalcount-leftcount 
            if leftcount>(i+1)//2 and rightcount>(len(nums)-(i+1))//2:
                return i
        return -1                   