class Solution:
    def secondGreaterElement(self, nums: List[int]) -> List[int]:
        n=len(nums)
        res=[-1]*(n)
        s1=[]
        s2=[]
        for i,num in enumerate(nums):
            temp=[]
            while s2 and nums[s2[-1]]<num:
                idx=s2.pop()
                res[idx]=num
            while s1 and nums[s1[-1]]<num:
                temp.append(s1.pop())
            while temp:
                s2.append(temp.pop())
            s1.append(i)
        return res
        