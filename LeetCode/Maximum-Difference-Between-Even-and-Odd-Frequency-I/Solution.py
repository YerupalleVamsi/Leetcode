class Solution:
    def maxDifference(self, s: str) -> int:
        map={}
        for ch in s:
            if ch in map:
                map[ch]+=1
            else:
                map[ch]=1
        diff=0
        even=0
        for val in map.values():
            if val%2==0:
                even=val
                break
        odd=0
        for idx,val in map.items():
            if(val%2==0):
                even=min(even,val)
            if(val%2==1):
                odd=max(odd,val)
               
        return odd-even
            

        