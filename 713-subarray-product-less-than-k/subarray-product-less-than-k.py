class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n=len(nums)
        l=0
        prod=1
        count=0
        for r in range(n):
            prod*=nums[r]
            while l<=r and prod>=k: 
                prod//=nums[l]
                l+=1
            count+=(r-l+1)
        return count


        