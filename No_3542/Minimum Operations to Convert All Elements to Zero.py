class Solution:
    def minOperations(self, nums: List[int]) -> int:
        stack = []
        ans = 0
        
        for num in nums:
            if num == 0:
                ans += len(stack)
                stack.clear()
            else:
                while stack and stack[-1] >= num:
                    if stack[-1] > num:
                        ans += 1
                    stack.pop()
                stack.append(num)
        
        ans += len(stack)
        return ans