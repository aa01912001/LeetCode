class Solution:
    def canArrange(self, arr: List[int], k: int) -> bool:
        remainder_count = Counter([num % k for num in arr])

        for r, cnt in remainder_count.items():
            if r == 0:
                if cnt % 2 != 0:
                    return False
            elif k % 2 == 0 and r == k // 2:
                if cnt % 2 != 0:
                    return False
            else:
                if remainder_count[r] != remainder_count[k - r]:
                    return False

        return True