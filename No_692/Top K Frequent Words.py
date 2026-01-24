class Solution:
    def topKFrequent(self, words: list[str], k: int) -> list[str]:
        counts = Counter(words)
        
        h = []
        for word, freq in counts.items():
            heapq.heappush(h, WordFreq(word, freq))
            if len(h) > k:
                heapq.heappop(h)
        
        ans = []
        while h:
            ans.append(heapq.heappop(h).word)
        return ans[::-1]

class WordFreq:
    def __init__(self, word, freq):
        self.word = word
        self.freq = freq
        
    def __lt__(self, other):
        if self.freq != other.freq:
            return self.freq < other.freq

        return self.word > other.word