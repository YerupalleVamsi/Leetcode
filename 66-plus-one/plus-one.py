class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        sum=0
        size=len(digits)
        n=size-1
        list=[]
        for i in range(size):
            sum+=(10**n)*digits[i]
            n-=1
        sum=sum+1    
        while sum>0:
            list.append(sum%10)
            sum=sum//10

        list.reverse()    
        return list