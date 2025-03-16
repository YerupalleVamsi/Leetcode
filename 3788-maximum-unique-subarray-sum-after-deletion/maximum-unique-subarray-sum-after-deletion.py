class Solution(object):
    def maxSum(self, nums):
        if len(nums)==1:
            return nums[0]
        unq=sorted(set(nums))
        sum=0
        for n in unq:
            if(n>0):
                sum+=n
        if(sum>0):
            return sum
        return unq[-1]            

        
        