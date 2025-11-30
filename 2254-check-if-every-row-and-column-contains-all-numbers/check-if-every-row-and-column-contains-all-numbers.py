class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n = len(matrix)
        total = set()
        for i in range(1,n+1):
            total.add(i)
        for i in range(n):
            s = set()
            for j in range(n):
                s.add(matrix[i][j])
            if(s!=total):
                return False
        for i in range(n):
            s = set()
            for j in range(n):
                s.add(matrix[j][i])
            if(s!=total):
                return False
        return True