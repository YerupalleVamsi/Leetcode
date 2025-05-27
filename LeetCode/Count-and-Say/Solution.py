class Solution:
    def memory(self, n):  
        map = []
        count=1
        for i in range(1,len(n)+1):
            if i<len(n) and n[i]==n[i-1]:
                count+=1
            else:
                map.append((count,n[i-1]))
                count=1
        return map

    def count(self, map):  
        ans = ""
        for count,digit in map:
            ans += str(count) +digit 
        return ans

    def countAndSay(self, n: int) -> str:
        res = "1"
        for _  in range(1,n):
            map = self.memory(res) 
            res = self.count(map)   
            
        return res
