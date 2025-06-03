class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        note = [0] * 26
        mag = [0] * 26
        for w in ransomNote:
            note[ord(w) - ord('a')] += 1
        for w in magazine:
            mag[ord(w) - ord('a')] += 1

        for i in range(26):
            if note[i] > mag[i]:
                return False
        return True
