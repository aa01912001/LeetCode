class Solution:
    def findTheDistanceValue(self, arr1: list[int], arr2: list[int], d: int) -> int:
        arr2.sort()
        ans = 0
        n2 = len(arr2)
        
        for num in arr1:
            left, right = 0, n2 - 1
            while left < right:
                mid = left + (right - left) // 2
                if arr2[mid] >= num:
                    right = mid
                else:
                    left = mid + 1
            
            if abs(arr2[right] - num) <= d:
                continue
                

            if right > 0 and abs(arr2[right - 1] - num) <= d:
                continue
                
            ans += 1
            
        return ans