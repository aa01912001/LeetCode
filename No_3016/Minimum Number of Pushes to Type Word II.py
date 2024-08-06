class Solution:
    def minimumPushes(self, word: str) -> int:
        counter = [0] * 26
        for c in word:
            counter[ord(c) - ord('a')] += 1
            
        counter.sort(reverse=True)
        
        ret = 0
        char_num = 0
        KEY_NUM = 8
        
        for count in counter:
            ret += ((int)(char_num / KEY_NUM) + 1) * count
            char_num += 1
        
        return ret