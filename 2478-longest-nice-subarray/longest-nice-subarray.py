class Solution:
    def longestNiceSubarray(self, nums: List[int]) -> int:
        left=0
        n=len(nums)
        sum=0
        maxlen=0
        for right in range(n):
            while((sum&nums[right])!=0):
                sum^=nums[left]
                left+=1
            sum|=nums[right]
            maxlen=max(maxlen,right-left+1)
        return maxlen        
        