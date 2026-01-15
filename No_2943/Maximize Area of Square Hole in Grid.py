class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        def max_side(bars: List[int]) -> int:
            bars.sort()
            max_streak = streak = 0
            prev = -1

            for bar in bars:
                if bar == prev + 1:
                    streak += 1
                else:
                    streak = 1
                prev = bar
                max_streak = max(max_streak, streak)

            return max_streak + 1

        side = min(max_side(hBars), max_side(vBars))
        return side * side