class Solution:
    def check(self,n:int,mid:int,batteries:List[int])->bool:
        sum = 0
        for e in batteries:
            sum+= min(mid,e)
            if(sum >= mid*n):
                 return True
        return False

    def maxRunTime(self, n: int, batteries: List[int]) -> int:
        N = len(batteries)
        low  = 0
        high = 10**15
        batteries.sort()
        best = 0
        while low<=high:
            mid = (high+low)//2
            if(self.check(n,mid,batteries)):
                best = mid
                low  = mid+1
            else:
                high = mid-1
        return best

