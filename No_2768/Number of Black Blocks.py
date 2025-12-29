class Solution:
    def countBlackBlocks(self, m: int, n: int, coordinates: List[List[int]]) -> List[int]:
        block_black_count = defaultdict(int)

        for x, y in coordinates:
            for dx, dy in ((0, 0), (-1, 0), (0, -1), (-1, -1)):
                top_x, top_y = x + dx, y + dy
                if 0 <= top_x < m - 1 and 0 <= top_y < n - 1:
                    block_black_count[(top_x, top_y)] += 1

        freq = Counter(block_black_count.values())
        ans = [0] * 5

        for black_cnt, block_cnt in freq.items():
            ans[black_cnt] = block_cnt

        total_blocks = (m - 1) * (n - 1)
        ans[0] = total_blocks - sum(ans[1:])

        return ans