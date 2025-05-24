class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1)>len(s2):
            return False
        hash=[0]*26
        for ch in s1:
            hash[ord(ch)-ord('a')]+=1
        k=len(s1)
        for i in range(len(s2)-k+1):
            temphash=[0]*26
            for j in range(i,i+k):
                temphash[ord(s2[j])-ord('a')]+=1
            if temphash==hash:
                return True
        return False



        
        