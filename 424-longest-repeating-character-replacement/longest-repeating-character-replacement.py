class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        start=0
        max_len=0
        max_count=0
        charfreq=defaultdict(int)
        for end in range(len(s)):
            charfreq[s[end]]+=1
            max_count=max(max_count,charfreq[s[end]])
            if (end-start+1)-max_count>k:
                charfreq[s[start]]-=1
                start+=1
            max_len=max(max_len,end-start+1)
        return max_len



        