class Solution:
    def longestPalindrome(self, s: str) -> int:
        count=Counter(s)
        maxlen=0
        hasodd=False
        for freq in count.values():
            if freq%2==0:
                maxlen+=freq
            else:
                maxlen+=freq-1
                hasodd=True
        if hasodd:
            maxlen+=1
        return maxlen
        


        