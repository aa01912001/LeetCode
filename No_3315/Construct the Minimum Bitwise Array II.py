class Solution:
    def minBitwiseArray(self, nums: List[int]) -> List[int]:
        ans = [-1] * len(nums)

        for i, num in enumerate(nums):
            bit = 1 << num.bit_length()

            while bit > 0:
                if num & bit:
                    candidate = num ^ bit
                    if candidate | (candidate + 1) == num:
                        ans[i] = candidate
                        break
                bit >>= 1

        return ans
