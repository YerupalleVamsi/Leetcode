class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        n=len(nums)
        res=[]
        for i in range(n-3):
            if i>0 and nums[i-1]==nums[i]:
                continue
            for j in range(i+1,n-2):
                if j>i+1 and nums[j-1]==nums[j]:
                    continue
                start=j+1
                end=n-1
                while start<end:
                    sum=nums[i]+nums[j]+nums[start]+nums[end]
                    if sum==target:
                        res.append([nums[i],nums[j],nums[start],nums[end]])
                        while start < end and nums[start] == nums[start + 1]:
                            start += 1
                        while start < end and nums[end] == nums[end - 1]:
                            end -= 1
                        start+=1
                        end-=1
                    elif sum<target:
                        start+=1
                    else:
                        end-=1
        return  res
            


        