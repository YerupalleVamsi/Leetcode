class Solution:
    def kidsWithCandies(self, candies: List[int], extraCandies: int) -> List[bool]:
        boolarray=[]
        maxcandies=max(candies)
        for num in candies:
            total=num+extraCandies
            if total>=maxcandies:
                boolarray.append(True)
            else:
                boolarray.append(False)
        return boolarray
        