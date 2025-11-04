class Solution:
    def continuousSubarrays(self, nums: List[int]) -> int:
        max_dq = deque()
        min_dq = deque() 
        left = 0
        ans = 0
        
        for right, x in enumerate(nums):
            while max_dq and max_dq[-1] < x:
                max_dq.pop()
            max_dq.append(x)
            
            while min_dq and min_dq[-1] > x:
                min_dq.pop()
            min_dq.append(x)
            
            while max_dq[0] - min_dq[0] > 2:
                if nums[left] == max_dq[0]:
                    max_dq.popleft()
                if nums[left] == min_dq[0]:
                    min_dq.popleft()
                left += 1
            
            ans += right - left + 1
        
        return ans