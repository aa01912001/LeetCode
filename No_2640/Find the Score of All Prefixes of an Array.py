class Solution:
    def findPrefixScore(self, nums: List[int]) -> List[int]:
        n = len(nums)
        ans = [0] * n
        ans[0] = 2 * nums[0]
        cur_max =  nums[0]

        for i in range(1, n):
            cur_max = max(cur_max, nums[i])
            ans[i] = ans[i-1] + nums[i] + cur_max
        
        return ans