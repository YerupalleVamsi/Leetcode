class Solution:

    def repairCars(self, ranks: List[int], cars: int) -> int:
        left = 1
        right = cars*cars*ranks[0]
        while left < right:
            mid = (left + right) // 2
            cars_repaired=sum(isqrt(mid//rank) for rank in ranks)
            if cars_repaired<cars:
                left=mid+1
            else:
                right=mid
        return left


        