class Solution:
    def maxFrequency(self, nums: List[int], k: int) -> int:
        '''  maxcount=1
         nums.sort()
         for i in range(1,len(nums)):
            currfreq=1
            currk=k
            currpos=i-1
            while currpos>=0:
                diff=nums[i]-nums[currpos]
                if(diff<=currk):
                    currk-=diff
                    currfreq+=1
                else:
                    break
                currpos-=1
            maxcount=max(currfreq,maxcount)
        return maxcount '''  # O(n^2) TLE
        nums.sort()
        left=0
        sum=0
        maxcount=1
        for i in range(len(nums)):
            sum+=nums[i]
            while (i-left+1)*nums[i] - sum >k:
                sum-=nums[left]
                left+=1
            maxcount=max(maxcount,i-left+1)
        return maxcount





        