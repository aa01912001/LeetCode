class Solution:
    def validStrings(self, n: int) -> List[str]:
        def generator(ret: list[str], s: string, n: int):
            if len(s) > 1 and s[-1] == '0' and s[-2] == '0':
                return

            if n == 0:
                ret.append(s)
                return

            s += '0'
            generator(ret, s, n-1)
            s = s[:-1]

            s += '1'
            generator(ret, s, n-1)
            s = s[:-1]

        ret = []
        generator(ret, "", n)
        return ret
        