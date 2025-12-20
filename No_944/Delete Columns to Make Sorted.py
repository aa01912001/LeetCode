class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        return sum(
            any(col[i] < col[i - 1] for i in range(1, len(col)))
            for col in zip(*strs)
        )