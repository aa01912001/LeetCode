import math

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        potions.sort()
        m = len(potions)
        ans = []

        for spell in spells:
            target = math.ceil(success / spell)
            left, right = 0, m
            while left < right:
                mid = (left + right) // 2
                if potions[mid] >= target:
                    right = mid
                else:
                    left = mid + 1
            ans.append(m - left)

        return ans
