class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        n=len(nums)
        xor1=0
        xor2=0
        for i in range(n):
            xor1^=nums[i]
        for i in range(1,n+1):
            xor2^=i
        for num in nums:
            if nums.count(num)==2:
                dup=num
                break
        missing=xor1^xor2^dup
        return [dup,missing]


        
            

        