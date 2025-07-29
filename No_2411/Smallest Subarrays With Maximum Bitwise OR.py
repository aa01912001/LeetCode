class Solution:
    def smallestSubarrays(self, nums: List[int]) -> List[int]:
        bit_index = {}
        n = len(nums)
        ans = [1] * n

        def update_bit_index(index, num):
            bit = 0
            while num:
                if num & 1:
                    bit_index[bit] = index
                num >>= 1
                bit += 1
        
        for i in range(n - 1, -1, -1):
            update_bit_index(i, nums[i])
            ans[i] = max(bit_index.values(), default=i) - i + 1
        
        return ans