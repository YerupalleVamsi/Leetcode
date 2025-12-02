class Solution:
    
    def countTrapezoids(self, points: List[List[int]]) -> int:
        MOD = 10**9+7
        mp = {}
        
        for x,y in points:
            if y not in mp:
                mp[y]=1
            else:
                mp[y]+=1
        
        pairs=0
        res = 0
        for y in mp.keys():
            count = mp[y]
            pairs+=comb(count,2)

        for y in mp.keys():
            count = mp[y]
            curr = comb(count,2)
            res+= (curr * (pairs-curr))%MOD
        
        return (res//2)%MOD