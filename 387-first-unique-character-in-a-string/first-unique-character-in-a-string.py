class Solution(object):
    def firstUniqChar(self, s):
        frequency = [0] * 26 

        for char in s:
            frequency[ord(char) - ord('a')] += 1  

        for index, char in enumerate(s):
            if frequency[ord(char) - ord('a')] == 1:
                return index  
        
        return -1
        