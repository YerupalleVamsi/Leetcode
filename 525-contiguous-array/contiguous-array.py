from typing import List

class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        if len(nums)/2 == sum(nums):
            return len(nums)
        index_map = {0: -1}  
        max_length = 0
        diff = 0
        for i, num in enumerate(nums):
            diff += 1 if num == 1 else -1  
            if diff in index_map:
                max_length = max(max_length, i - index_map[diff]) #so if i get the same diff again ill update the length 
            else:
                index_map[diff] = i  # Store first occurrence only
        return max_length

            





        