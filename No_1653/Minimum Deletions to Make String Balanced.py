class Solution:
    def minimumDeletions(self, s: str) -> int:
        '''
            dp[0]: minimum deletions to make end of string to be 'a'
            dp[1]: minimum deletions to make end of string to be 'b'
        '''
        dp = [0, 0]
        
        for c in s:
            if c == 'a':
                dp[1] += 1
            else:
                dp[1] = min(dp[0], dp[1])
                dp[0] = dp[0] + 1
                
        return min(dp)