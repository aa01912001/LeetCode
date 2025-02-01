class Solution:
    def findWinningPlayer(self, skills: List[int], k: int) -> int:
        ret = 0
        remaining = k

        for i, num in enumerate(skills[1:], start=1):
            if skills[ret] > num:
                remaining -= 1
            else:
                ret = i
                remaining = k - 1
            if remaining == 0:
                return ret

        return ret
        