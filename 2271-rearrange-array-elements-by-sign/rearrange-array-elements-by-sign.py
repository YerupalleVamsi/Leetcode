class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        pos=[]
        neg=[]
        for i in nums:
            if i>0:
                pos.append(i)
            else:
                neg.append(i)
        list2=[]
        for i in range(max(len(pos),len(neg))):
            list2.append(pos[i])
            list2.append(neg[i])
        
        return list2
              
        