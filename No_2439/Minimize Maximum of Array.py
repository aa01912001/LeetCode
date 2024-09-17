class Solution:
    def minimizeArrayValue(self, nums: List[int]) -> int:
        def checkSatisfied(nums, target):
            carry = 0
            for num in nums[:0:-1]:
                if carry + num <= target:
                    carry = 0
                else:
                    carry = num + carry - target
            
            return True if nums[0] + carry <= target else False
        
        low = 0
        high = int(1e9)
        
        while low < high:
            mid = low + (high - low) // 2
            if checkSatisfied(nums, mid):
                high = mid
            else:
                low = mid + 1
                
        return high