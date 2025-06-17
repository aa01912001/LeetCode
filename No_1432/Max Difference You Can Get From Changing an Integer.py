class Solution:
    def maxDiff(self, num: int) -> int:
        max_str = min_str = str(num)
        
        for i, ch in enumerate(max_str):
            if ch != '9':
                max_str = max_str.replace(ch, '9')
                break

        for i, ch in enumerate(min_str):
            if i == 0 and ch != '1':
                min_str = min_str.replace(ch, '1')
                break

            if ch != '0' and ch != min_str[0]:
                min_str = min_str.replace(ch, '0')
                break

        
        return int(max_str) - int(min_str)
        