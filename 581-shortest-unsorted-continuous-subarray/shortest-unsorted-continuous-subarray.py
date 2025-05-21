class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        i=0
        j=len(nums)-1
        currmax=float('-inf')
        currmin=float('inf')
        start=0
        end=-1
        while(j>=0):
            if nums[i]>=currmax:
                currmax=nums[i]
            else:
                end=i
            if nums[j]<=currmin:
                currmin=nums[j]
            else:
                start=j
            i+=1
            j-=1
        return end-start+1
        

        