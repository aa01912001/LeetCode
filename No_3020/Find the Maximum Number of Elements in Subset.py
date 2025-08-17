class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        counter = Counter(nums)
        ans = 0

        def helper(num):
            if num == 1:
                if counter[1] > 1:
                    return 2
                else:
                    return 0

            x = int(sqrt(num))
            if (x * x != num) or (x not in counter) or (counter[x] < 2):
                return 0

            return 2 + helper(x)

        for k in counter.keys():
            if k == 1:
                ans = max(ans, counter[k] if counter[k] % 2 == 1 else counter[k] - 1)
                continue
            ans = max(ans, 1 + helper(k))
        
        return ans