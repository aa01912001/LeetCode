# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        target_nodes = set(nums)
        dummy = ListNode()
        dummy.next = head
        pre = dummy

        while pre.next != None:
            if pre.next.val in target_nodes:
                pre.next = pre.next.next
            else:
                pre = pre.next

        return dummy.next