class Solution:
	def countDaysTogether(self, arriveAlice: str, leaveAlice: str, arriveBob: str, leaveBob: str) -> int:
		month_days = [0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
		
		def convert_to_days(date_str: str) -> int:
			month = int(date_str[:2])
			day = int(date_str[3:])
			return sum(month_days[:month]) + day
		
		alice_start = convert_to_days(arriveAlice)
		alice_end = convert_to_days(leaveAlice)
		bob_start = convert_to_days(arriveBob)
		bob_end = convert_to_days(leaveBob)
		
		max_start = max(alice_start, bob_start)
		min_end = min(alice_end, bob_end)
		
		return max(0, min_end - max_start + 1)