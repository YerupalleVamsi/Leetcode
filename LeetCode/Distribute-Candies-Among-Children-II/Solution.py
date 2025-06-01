class Solution:
    def distributeCandies(self, n: int, limit: int) -> int:
        ways=0
        A_min=max(0,n-2*limit)
        A_max=min(limit,n)
        for i in range(A_min,A_max+1):
            rem_candies=n-i
            B_min=max(0,rem_candies-limit)
            B_max=min(limit,rem_candies)
            ways+=B_max-B_min+1
        return ways