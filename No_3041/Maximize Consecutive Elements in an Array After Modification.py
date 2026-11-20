class Solution:
	def maxSelectedElements(self, nums: List[int]) -> int:
		nums.sort()
		# dp[x] stores the max length of consecutive elements ending at value x
		dp= defaultdict(int)
		ans = 0

		for num in nums:
			# Option 1: increase num by 1 to extend a sequence ending at num
			dp[num + 1] = dp[num] + 1
			# Option 2: keep num as is to extend a sequence ending at num - 1
			dp[num] = dp[num - 1] + 1

			ans = max(ans, dp[num], dp[num + 1])

		return ans