class Solution:
    def sumofdigits(self,n:int)->int:
        sum=0
        while n>0:
            sum+=n%10
            n=n//10
        return sum
        
    def minElement(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            nums[i]=self.sumofdigits(nums[i])
        return min(nums)
            
        