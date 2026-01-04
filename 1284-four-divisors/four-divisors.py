class Solution:
    def count_divisors(self,num):
        cnt = 0
        sum = 0
        for i in range(2,int(num**0.5)+1):
            if(num%i==0):
                if i == num // i:
                    return 0
                cnt+=1
                sum+=i
                if cnt>1 : 
                    return 0
        if cnt==0:
            return 0
        if cnt==1:
            res = 1 + sum + (num // sum) + num
            return res
        return 0
    def sumFourDivisors(self, nums: List[int]) -> int:
        sum = 0 
        for num in nums:
            sum+= self.count_divisors(num)
        return sum

        