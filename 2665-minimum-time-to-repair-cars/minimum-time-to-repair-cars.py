class Solution:
    def repair(self, ranks: List[int], m: int, cars: int) -> bool:
        count = 0
        for rank in ranks:
            num_cars=int((m//rank)**0.5)
            count+=num_cars
            if count>=cars:
                return True
        return False

    def repairCars(self, ranks: List[int], cars: int) -> int:
        left = 1
        right = min(ranks) * (cars ** 2)

        while left < right:
            mid = (left + right) // 2
            if self.repair(ranks, mid, cars):
                right = mid
            else:
                left = mid + 1

        return left


        