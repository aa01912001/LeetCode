class Solution:
    def minimumRemoval(self, beans: List[int]) -> int:
        n = len(beans)
        total = sum(beans)

        beans.sort()

        ans = total
        for idx, num in enumerate(beans):
            if (val:= total - num*(n - idx)) < ans:
                ans = val
        return ans
        