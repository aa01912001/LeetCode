class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        num_cells = len(cells)
        parent = list(range(num_cells + 2))
        LEFT_BOUND = 0
        RIGHT_BOUND = num_cells + 1
        
        grid_status = {}
        
        def find(i: int) -> int:
            if parent[i] == i:
                return i
            parent[i] = find(parent[i]) # path compression
            return parent[i]

        def union(i: int, j: int):
            root_i = find(i)
            root_j = find(j)
            if root_i != root_j:
                parent[root_i] = root_j

        DIRECTIONS = [
            (-1, 0), (1, 0), (0, -1), (0, 1),
            (-1, -1), (-1, 1), (1, -1), (1, 1)
        ]

        for i, (r, c) in enumerate(cells):
            day_idx = i + 1
            grid_status[(r, c)] = day_idx
            
            if c == 1:
                union(day_idx, LEFT_BOUND)
            if c == col:
                union(day_idx, RIGHT_BOUND)
                
            for dr, dc in DIRECTIONS:
                nr, nc = r + dr, c + dc
                if (nr, nc) in grid_status:
                    union(day_idx, grid_status[(nr, nc)])
            
            if find(LEFT_BOUND) == find(RIGHT_BOUND):
                return i
                
        return row * col