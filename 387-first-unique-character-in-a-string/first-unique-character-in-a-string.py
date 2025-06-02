class Solution:
    def firstUniqChar(self, s: str) -> int:
        map={}
        for w in s:
            if w not in map:
                map[w]=1
            else:
                map[w]+=1
        word=""
        for key,val in map.items():
            if val==1:
                word=key
                break
        if word=="":return -1
        for i in range(len(s)):
            if s[i]==word:
                return i
        

                
        