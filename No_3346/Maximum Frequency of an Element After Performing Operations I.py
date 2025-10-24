class Solution:
    def maxFrequency(self, nums: List[int], k: int, num_operations: int) -> int:
        freq = Counter(nums)
        events = []
        for num in nums:
            events.extend(
                [
                    (num-k, 1), 
                    (num-1, -1), 
                    (num, 1), 
                    (num, -1), 
                    (num+1, 1), 
                    (num+k, -1)
                ]
            )

        events.sort(key=lambda e: (e[0], -e[1]))

        max_freq = max(freq.values())
        active_count = 0

        for value, delta in events:
            active_count += delta
            base_count = freq.get(value, 0)
            possible_freq = base_count + min(active_count - base_count, num_operations)
            max_freq = max(max_freq, possible_freq)

        return max_freq
