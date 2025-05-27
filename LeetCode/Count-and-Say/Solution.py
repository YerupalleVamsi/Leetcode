class Solution:
    def countAndSay(self, n: int) -> str:
        res = "1"
        for _ in range(1, n):
            temp = ""
            count = 1
            for i in range(1, len(res) + 1):
                if i < len(res) and res[i] == res[i - 1]:
                    count += 1
                else:
                    temp += str(count) + res[i - 1]
                    count = 1
            res = temp
        return res

