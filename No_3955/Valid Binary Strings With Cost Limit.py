class Solution:
	def generateValidStrings(self, n: int, k: int) -> list[str]:
		ans: list[str] = []
		
		def dfs(s: str, cost: int, index: int) -> None:
			if cost > k:
				return
			
			if len(s) == n:
				ans.append(s)
				return
			
			dfs(s + '0', cost, index + 1)
			
			if not s or s[-1] != '1':
				dfs(s + '1', cost + index + 1, index + 1)
		
		dfs('', 0, -1)
		return ans