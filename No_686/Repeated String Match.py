class Solution:
	def repeatedStringMatch(self, a: str, b: str) -> int:
		min_repeats = ceil(len(b) / len(a))
		repeated_a = a * min_repeats

		if b in repeated_a:
			return min_repeats

		if b in repeated_a + a:
			return min_repeats + 1

		return -1