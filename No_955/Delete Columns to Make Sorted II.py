class Solution:
    def minDeletionSize(self, strs: List[str]) -> int:
        rows = len(strs)
        cols = len(strs[0])

        deleted_cols = 0
        sorted_pair = [False] * rows  # sorted_pair[i] means strs[i-1] < strs[i] is already confirmed

        for c in range(cols):
            newly_sorted = [False] * rows
            need_delete = False

            for r in range(1, rows):
                if sorted_pair[r]:
                    continue

                if strs[r][c] < strs[r - 1][c]:
                    deleted_cols += 1
                    need_delete = True
                    break
                elif strs[r][c] > strs[r - 1][c]:
                    newly_sorted[r] = True

            if not need_delete:
                for i in range(rows):
                    sorted_pair[i] |= newly_sorted[i]

        return deleted_cols
