class Solution:
    def singleNonDuplicate(self, arr: List[int]) -> int:
         n = len(arr)
         if n == 1:
            return arr[0]
         if arr[0] != arr[1]:  
            return arr[0]
         if arr[-1] != arr[-2]:  
            return arr[-1]

         left, right = 0, n - 1

         while left <= right:
             mid = left + (right - left) // 2
             if arr[mid] != arr[mid - 1] and arr[mid] != arr[mid + 1]:
                 return arr[mid]
             if (mid % 2 == 0 and arr[mid] == arr[mid + 1]) or (mid % 2 == 1 and arr[mid] == arr[mid - 1]):
                 left = mid + 1
             else:
                 right = mid - 1

         return -1
        