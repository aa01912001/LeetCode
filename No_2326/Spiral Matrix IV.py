# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def spiralMatrix(self, m: int, n: int, head: Optional[ListNode]) -> List[List[int]]:
        ans = [[-1] * n for _ in range(m)]
        
        def traverse(cur_x: int, cur_y: int, fill_count: int, move_x: int, move_y: int):
            nonlocal head
            ans[cur_y][cur_x] = head.val
            head = head.next
            if head is None:
                return
            
            fill_count -= 1
            if fill_count:
                return traverse(cur_x + move_x, cur_y + move_y, fill_count, move_x, move_y)
            
            if move_x:
                move_y = 1 if move_x == 1 else -1
                fill_count = m - 2 * cur_y - 1 if move_x == 1 else m - 2 * (m - cur_y)
                move_x = 0
            else:
                move_x = -1 if move_y == 1 else 1
                fill_count = n - 2 * (n - cur_x - 1) - 1 if move_y == 1 else n - 2 * (cur_x + 1)
                move_y = 0
                

            return traverse(cur_x + move_x, cur_y + move_y, fill_count, move_x, move_y)

        traverse(0, 0, n, 1, 0)
        return ans

                
            
