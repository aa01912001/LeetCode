class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        type_count = defaultdict(int)
        ans = 0

        left = 0
        for right in range(len(fruits)):
            right_type = fruits[right]
            type_count[right_type] += 1
            while len(type_count) > 2:
                left_type = fruits[left]
                type_count[left_type] -= 1
                if type_count[left_type] == 0:
                    type_count.pop(left_type)
                left += 1
            
            ans = max(ans, right-left+1)

        return ans
