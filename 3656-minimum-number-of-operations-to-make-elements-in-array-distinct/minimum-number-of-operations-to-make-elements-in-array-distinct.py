class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        count=0
        if len(nums)==len(set(nums)):
            return 0
        while len(nums)!=len(set(nums)) and len(nums)>3:
            del nums[:3]
            count+=1
        if len(nums)==len(set(nums)):
            return count 
        if len(nums)!=len(set(nums)) and len(nums)<=3:
            count+=1
        return count
        

        