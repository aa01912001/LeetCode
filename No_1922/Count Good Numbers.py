class Solution:
    def countGoodNumbers(self, n: int) -> int:
        MOD = 10**9 + 7

        def mod_pow(base, exp):
            if exp == 0:
                return 1
     
            if exp % 2 == 0:
                half = mod_pow(base, exp // 2)
                return (half * half) % MOD
            else:
                return (base * mod_pow(base, exp - 1)) % MOD

        even_count = (n + 1) // 2
        odd_count = n // 2

        return (mod_pow(5, even_count) * mod_pow(4, odd_count)) % MOD
