class Solution:
    def generate(self, numRows: int) -> List[List[int]]:
        ans = [[1]]
        for row in range(2, numRows+1):
            cur = [1]
            for i in range(2, row):
                cur.append(ans[-1][i-2]+ans[-1][i-1])
            cur.append(1)
            ans.append(cur)

        return ans


