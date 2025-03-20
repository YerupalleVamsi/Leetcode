class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        neg=[num for num in nums if num<0]
        pos=[num for num in nums if num>0]    
        ans=[]
        x=0
        y=0
        while x<len(pos) and y<len(neg):
            ans.append(pos[x])
            x+=1
            ans.append(neg[y])
            y+=1
        return ans        

              
        