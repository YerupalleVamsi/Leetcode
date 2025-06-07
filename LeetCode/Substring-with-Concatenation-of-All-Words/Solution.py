class Solution:
    def findSubstring(self, s: str, words: List[str]) -> List[int]:
        res=[]
        windowsize=len(words[0])*len(words)
        wordsize=len(words[0])
        if windowsize>len(s):
            return []
        w_map={}
        for word in words:
            if word in w_map:
                w_map[word]+=1
            else:
                w_map[word]=1
        l,r=0,0
        for i in range(wordsize):
            l=r=i 
            seen={}
            while (r<=len(s)-wordsize):
                currword=s[r:r+wordsize]
                r+=wordsize
                if currword in w_map:
                    seen[currword] = seen.get(currword, 0) + 1
                    while seen[currword]>w_map[currword]:
                        rm=s[l:l+wordsize]
                        seen[rm]-=1
                        l+=wordsize
                    if r-l==windowsize:
                        res.append(l)
                else:
                    seen.clear()
                    l=r
        return res




            
        

        