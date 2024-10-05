class Solution:
    def dividePlayers(self, skill: List[int]) -> int:
        target = sum(skill) // (len(skill) // 2)
        freq = defaultdict(int)
        ret = 0
        
        for num in skill:
            gap = target - num
            if gap in freq:
                freq[gap] -= 1
                if freq[gap] == 0:
                    freq.pop(gap)
                ret += num * gap
            else:
                freq[num] += 1
        
        return ret if not freq else -1