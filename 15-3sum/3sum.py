class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        ans=set()
        n=len(nums)
        for i in range(n-2):
            if i>0 and nums[i]==nums[i-1]:
                continue
            lookup={}
            for j in range(i+1,n):
                    tar = -(nums[i]+nums[j])
                    if  tar in lookup:
                        ans.add((nums[i],tar,nums[j]))    
                    lookup[nums[j]]= j
        return [list(triplet) for triplet in ans]




        