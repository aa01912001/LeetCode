class Solution:
	def countServers(self, n: int, logs: list[list[int]], x: int, queries: list[int]) -> list[int]:
		logs.sort(key=lambda item: item[1])
		sorted_queries = sorted(enumerate(queries), key=lambda item: item[1])
		
		ans = [0] * len(queries)
		server_counts: dict[int, int] = defaultdict(int)
		active_servers = 0
		left, right = 0, 0
		log_length = len(logs)
		
		for original_idx, q_time in sorted_queries:
			# Expand right boundary: include logs within current query time (<= q_time)
			while right < log_length and logs[right][1] <= q_time:
				server = logs[right][0]
				if server_counts[server] == 0:
					active_servers += 1
				server_counts[server] += 1
				right += 1
				
			# Shrink left boundary: exclude logs earlier than window start (< q_time - x)
			while left < log_length and logs[left][1] < q_time - x:
				server = logs[left][0]
				server_counts[server] -= 1
				if server_counts[server] == 0:
					active_servers -= 1
				left += 1
				
			# Total servers minus active servers gives the number of idle servers
			ans[original_idx] = n - active_servers
			
		return ans