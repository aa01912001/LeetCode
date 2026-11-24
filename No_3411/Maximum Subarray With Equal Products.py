class Solution:
    def maxLength(self, nums: list[int]) -> int:
        def get_gcd(a: int, b: int) -> int:
            while b:
                a, b = b, a % b
            return a

        n = len(nums)
        ans = 1

        for i in range(n):
            prod = gcd = lcm = nums[i]
            for j in range(i + 1, n):
                num = nums[j]
                prod *= num
                gcd = get_gcd(gcd, num)
                lcm = lcm * num // get_gcd(lcm, num)

                if prod == lcm * gcd:
                    ans = max(ans, j - i + 1)

        return ans