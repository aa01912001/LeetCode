class Solution:
    def nextLargerNodes(self, head: Optional[ListNode]) -> List[int]:
        ans = []
        stack = []  # (val, index)
        index = 0

        while head:
            ans.append(0)
            while stack and head.val > stack[-1][0]:
                _, idx = stack.pop()
                ans[idx] = head.val
            stack.append((head.val, index))
            index += 1
            head = head.next

        return ans