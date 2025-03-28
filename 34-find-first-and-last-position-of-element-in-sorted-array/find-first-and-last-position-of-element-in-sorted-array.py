from typing import List

class Solution:
    def searchRange(self, nums: List[int], target: int) -> List[int]:
        if target not in nums:
            return [-1, -1]

        low, high = 0, len(nums) - 1
        first = -1  
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                first = mid  
                high = mid - 1  
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

        low, high = 0, len(nums) - 1
        last = -1 
        while low <= high:
            mid = low + (high - low) // 2
            if nums[mid] == target:
                last = mid  
                low = mid + 1  
            elif nums[mid] < target:
                low = mid + 1
            else:
                high = mid - 1

        return [first, last]

            



        
        
        