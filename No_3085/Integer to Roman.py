class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        freqs = Counter(word).values()

        def get_operation_times(target):
            ret = 0
            for f in freqs:
                if f < target:
                    ret += f
                elif f > target + k:
                    ret += f - target - k
            return ret

        return min(get_operation_times(i) for i in range(len(word) + 1))