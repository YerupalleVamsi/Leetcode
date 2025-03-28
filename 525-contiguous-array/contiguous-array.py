class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        n=len(nums)
        if n==1:
            return 0
        n1,n2=0,0
        map={0:-1}
        diff=0
        m_length=0
        for i,num in enumerate(nums):
            if num==1:
                n1+=1
            else:
                n2+=1
            diff=n1-n2
            if diff not in map:
                map[diff]=i
            else:
                m_length=max(m_length,i-map[diff])
        return m_length
            





        