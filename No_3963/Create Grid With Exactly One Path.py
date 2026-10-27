class Solution:
    def createGrid(self, m: int, n: int) -> list[str]:
        grid = ['.' + '#' * (n - 1) for i in range(m-1)] 
        grid.append('.' * n)

        return grid