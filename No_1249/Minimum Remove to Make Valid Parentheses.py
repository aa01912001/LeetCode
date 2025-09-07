class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        l_count = 0
        result = []

        for c in s:
            if c == ')':
                if l_count == 0:
                    continue
                l_count -= 1
            elif c == '(':
                l_count += 1
            result.append(c)

        ans = []
        for c in reversed(result):
            if c == '(' and l_count > 0:
                l_count -= 1
                continue
            ans.append(c)

        return ''.join(reversed(ans))
