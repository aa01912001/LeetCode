class Solution:
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        MOD = 10**9 + 7
        h_gaps = self._all_gaps(hFences, m)
        v_gaps = self._all_gaps(vFences, n)

        max_side = -1
        for side in h_gaps:
            if side in v_gaps:
                max_side = max(max_side, side)

        if max_side == -1:
            return -1

        return (max_side * max_side) % MOD

    def _all_gaps(self, fences: List[int], limit: int) -> set:
        fences = sorted(fences + [1, limit])
        gaps = set()

        for i in range(len(fences)):
            for j in range(i + 1, len(fences)):
                gaps.add(fences[j] - fences[i])

        return gaps
