class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        NUM_OF_VERTEX = 26
        length = len(original)
        dis = defaultdict(lambda: float('inf'))
        
        for i, j, w in zip(original, changed, cost):
            if dis[(i, j)] > w:
                dis[(i, j)] = w
            
        for v in set(source):
            dis[(v, v)] = 0
        
        for k in ascii_lowercase:
            for i in ascii_lowercase:
                for j in ascii_lowercase:
                    dis[(i, j)] = min(dis[(i, j)], dis[(i, k)] + dis[(k, j)])
        ret = 0
        for s, t in zip(source, target):
            if dis[(s, t)] == float('inf'):
                return -1
            ret += dis[(s, t)]
            
        return ret