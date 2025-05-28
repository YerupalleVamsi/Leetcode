class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows, cols = len(mat), len(mat[0])
        res = [[-1 for _ in range(cols)] for _ in range(rows)] #acts as a visited list
        q = deque()

        # Step 1: Add all 0s to the queue and mark their distance as 0
        for r in range(rows):
            for c in range(cols):
                if mat[r][c] == 0:
                    res[r][c] = 0
                    q.append((r, c))

        # Step 2: BFS from all 0s
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        while q:
            r, c = q.popleft()
            for dr, dc in directions:
                nr, nc = r + dr, c + dc
                if 0 <= nr < rows and 0 <= nc < cols and res[nr][nc] == -1:
                    res[nr][nc] = res[r][c] + 1
                    q.append((nr, nc))

        return res
