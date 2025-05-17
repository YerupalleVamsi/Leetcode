class Solution:
    def sortedSquares(self, nums: List[int]) -> List[int]:
        n=len(nums)
        L,R=0,n-1
        index=n-1
        ans=[0]*n
        while L<=R :
            left=nums[L]*nums[L]
            right=nums[R]*nums[R]
            if left>right:
                ans[index]=left
                L+=1
                index-=1
            elif left<=right:
                ans[index]=right
                R-=1
                index-=1
                
        return ans           

        