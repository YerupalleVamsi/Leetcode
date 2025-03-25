class Solution(object):
    def reverse(self, x):
        INT_MAX, INT_MIN = 2**31 - 1, -2**31
        sign = -1 if x < 0 else 1
        x = abs(x)
        
        reversed_x = 0
        while x:
            reversed_x = reversed_x * 10 + x % 10
            x //= 10  
        
        reversed_x *= sign 
        
       
        if reversed_x < INT_MIN or reversed_x > INT_MAX:
            return 0
        return reversed_x

    
        