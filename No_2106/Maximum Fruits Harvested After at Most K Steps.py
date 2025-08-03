class Solution:
    def maxTotalFruits(self, fruits: List[List[int]], startPos: int, k: int) -> int:
        prefix_amount = []
        positions = []
        for i, fruit in enumerate(fruits):
            positions.append(fruit[0])
            if i == 0:
                prefix_amount.append(fruit[1])
            else:
                prefix_amount.append(prefix_amount[i-1] + fruit[1])

        ans = 0
        start_index = bisect.bisect_right(positions, startPos) - 1
        for i in range(len(positions)):
            pos = positions[i]
            if pos > startPos:
                break
            if startPos - pos > k:
                continue
            
            farthest_right_pos = pos + (k - (startPos - pos))
            target_index = bisect.bisect_right(positions, farthest_right_pos) - 1 
            if i == 0:
                total_amount = prefix_amount[max(target_index, start_index)]
            else:
                total_amount = prefix_amount[max(target_index, start_index)] - prefix_amount[i - 1]
            ans = max(ans, total_amount)

        start_index = bisect.bisect_left(positions, startPos)
        for i in range(len(positions)-1, -1, -1):
            pos = positions[i]
            if pos <= startPos:
                break
            if pos - startPos > k:
                continue
            
            farthest_left_pos = pos - (k - (pos - startPos))
            target_index = bisect.bisect_left(positions, farthest_left_pos)
            if min(target_index, start_index) == 0:
                total_amount = prefix_amount[i]
            else:   
                total_amount = prefix_amount[i] - prefix_amount[min(target_index, start_index) - 1]
            ans = max(ans, total_amount)
        
        return ans