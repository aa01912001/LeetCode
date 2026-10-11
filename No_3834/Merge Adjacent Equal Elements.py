class Solution:
    def mergeAdjacent(self, nums: List[int]) -> List[int]:
        stk = []
        for num in nums:
            while stk and stk[-1] == num:
                stk.pop()
                num *= 2
            stk.append(num)
        return stk