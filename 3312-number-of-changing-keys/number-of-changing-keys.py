class Solution:
    def countKeyChanges(self, s: str) -> int:
        x = s.lower()
        cnt=0
        for i in range(1,len(s)):
            if x[i]!=x[i-1]:
                cnt+=1
        return cnt
