class Solution:
    def sortMatrix(self, grid: List[List[int]]) -> List[List[int]]:
        # process bottom-left triangle
        n = len(grid)
        for i in range(n-1, -1, -1):
            diagonal_items = []
            x = 0
            y = i 
            while y < n:
                diagonal_items.append(grid[y][x])
                x += 1
                y += 1
            diagonal_items.sort(reverse=True)
            x = 0
            y = i
            while y < n:
                grid[y][x] = diagonal_items[x]
                x += 1
                y += 1

        # process top-right triangle
        for i in range(n-1, 0, -1):
            diagonal_items = []
            x = i
            y = 0 
            while x < n:
                diagonal_items.append(grid[y][x])
                x += 1
                y += 1
            diagonal_items.sort()
            x = i
            y = 0
            while x < n:
                grid[y][x] = diagonal_items[y]
                x += 1
                y += 1

        return grid