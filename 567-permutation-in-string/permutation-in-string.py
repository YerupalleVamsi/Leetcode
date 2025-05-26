class Solution:
    def isequal(self,a:List[int],b:List[int])-> bool:
        for i in range(26):
            if a[i]!=b[i]:
                return False
        return True
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1)>len(s2):
            return False
        hash1=[0]*26
        hash2=[0]*26
        for ch in s1:
            hash1[ord(ch)-ord('a')]+=1
        l,r=0,0
        while(r<len(s2)):
            hash2[ord(s2[r]) - ord('a')]+=1
            if (r-l+1==len(s1)):
                if(self.isequal(hash1,hash2)):
                    return True
            if (r-l+1<len(s1)):
                r+=1
            else:
                hash2[ord(s2[l]) - ord('a')]-=1
                l+=1
                r+=1
        return False


        
        