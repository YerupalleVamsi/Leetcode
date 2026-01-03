class Solution:
    def numOfWays(self, N: int) -> int:
        MOD = 10 ** 9 + 7
        
        p = []
        for i in range(3):
            for j in range(3):
                if i != j:
                    for k in range(3):
                        if j != k:
                            p.append((i, j, k))

        np = []
        for i in range(len(p)):
            np.append([])

            for j in range(len(p)):
                good = True
                for k in range(3):
                    if p[i][k] == p[j][k]:
                        good = False
                if good:
                    np[i].append(j)

        # index -> row number
        # prev_row_number -> the number in the p[i]
        @cache
        def f(index, prev_row_number):
            if index == N:
                return 1

            total = 0
            for j in range(len(np[prev_row_number])):
                total += f(index + 1, j)
            return total % MOD

        total = 0
        for i in range(len(np)):
            total += f(1, i)
        return total % MOD

        # precalculation