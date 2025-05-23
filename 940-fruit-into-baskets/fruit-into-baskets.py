class Solution:     
    def totalFruit(self, fruits: List[int]) -> int:

        max_len=1
        freq=defaultdict(int)
        left=0
        for i in range(len(fruits)):
            freq[fruits[i]]+=1
            while len(freq)>2:
                freq[fruits[left]]-=1
                if freq[fruits[left]]==0:
                    del freq[fruits[left]]
                left+=1
            
            max_len=max(i-left+1,max_len)
        return max_len
        