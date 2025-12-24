class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        total = sum(apple)
        capacity.sort(reverse=True)
        
        ans = 0
        for c in capacity:
            ans += 1
            total -= c
            if total <= 0:
                break
        
        return ans