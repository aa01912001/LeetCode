class Solution:
    def numberOfWeakCharacters(self, properties: List[List[int]]) -> int:
        n = len(properties)
        properties.sort()
        right_max_defense = [0] * n
        right_max_defense[-1] = properties[-1][1]
        for i in range(n-2, -1, -1):
            right_max_defense[i] = max(properties[i][1], right_max_defense[i+1])

        ans = 0
        for i in range(n-1):
            left = i + 1
            right = n
            while left < right:
                mid = left + (right - left) // 2
                if properties[i][0] < properties[mid][0]:
                    right = mid
                else:
                    left = mid + 1

            if right != n and properties[i][1] < right_max_defense[right]:
                ans += 1

        return ans

