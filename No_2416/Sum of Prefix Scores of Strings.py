class Trie:
    def __init__(self):
        self.count = 0
        self.children = defaultdict()
        
    def insert(self, s):
        cur = self
        for c in s:
            if c not in cur.children:
                cur.children[c] = Trie()
            cur = cur.children[c]
            cur.count += 1
            
    def countScores(self, s):
        total = 0
        cur = self
        for c in s:
            cur = cur.children[c]
            total += cur.count
                
        return total
        

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        t = Trie()
        for s in words:
            t.insert(s)
            
        ret = [t.countScores(s) for s in words]
        
        return ret
            
        