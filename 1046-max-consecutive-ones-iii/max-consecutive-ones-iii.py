class Solution:
    def longestOnes(self, nums: List[int], k: int) -> int:
        start=0
        max_len=0
        max_count=0
        freq=[0]*2
        for end in range(len(nums)):
            freq[nums[end]]+=1
            max_count=max(max_count,freq[1])
            if (end-start+1)-max_count>k:
                freq[nums[start]]-=1
                start+=1
            max_len=max(max_len,end-start+1)
        return max_len
        