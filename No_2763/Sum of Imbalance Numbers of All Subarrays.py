class Solution:
    def sumImbalanceNumbers(self, nums: List[int]) -> int:
        n = len(nums)
        ret = 0
        for i in range(n):
            s = set()
            count = -1
            for num in nums[i:]:
                if num not in s:
                    if (num - 1) not in s and (num + 1) not in s:
                        count += 1
                    elif (num - 1) in s and (num + 1) in s:
                        count -= 1
                
                s.add(num)
                ret += count
                
        return ret
                        