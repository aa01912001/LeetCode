class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m = len(grid)
        n = len(grid[0])
        
        dis = 0
        directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
        visited = [[-1] * n for _ in range(m)]
        q = collections.deque()
        q.append(((0, 0), k))

        while q:
            count = len(q)
            while count:
                cell, old_k = q.popleft()
                i, j = cell
                count -= 1
                
                if i == m - 1 and j == n - 1:
                    return dis
                for dr, dc in directions:
                    new_i = i + dr
                    new_j = j + dc
                    if new_i < 0 or new_i >= m or new_j < 0 or new_j >= n:
                        continue
                        
                    new_k = old_k - grid[new_i][new_j]
                    if new_k < 0:
                        continue
                        
                    if visited[new_i][new_j] >= new_k:
                        continue

                    visited[new_i][new_j] = new_k

                    q.append(((new_i, new_j), new_k))
            dis += 1
            
        return -1