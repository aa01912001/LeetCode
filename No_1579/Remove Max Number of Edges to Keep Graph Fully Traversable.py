class UnionFind():
    def __init__(self, n):
        self.__groups = [0] * (n + 1)
        self.__heights = [1] * (n + 1)
        self.components = n
    
    def Union(self, i, j):
        root1 = self.Find(i)
        root2 = self.Find(j)
    
        if root1 == root2:
            return 0
        
        if self.__heights[root1] < self.__heights[root2]:
            self.__groups[root1] = root2
            self.__heights[root2] = max(self.__heights[root2], self.__heights[root1] + 1)
        else:
            self.__groups[root2] = root1
            self.__heights[root1] = max(self.__heights[root1], self.__heights[root2] + 1)
    
        self.components -= 1
        return 1
    
    def Find(self, i):
        if self.__groups[i] == 0:
            return i
        
        self.__groups[i] = self.Find(self.__groups[i])
        return self.__groups[i]
    
    def is_connected(self):
        return self.components == 1
        

class Solution:
    def maxNumEdgesToRemove(self, n: int, edges: List[List[int]]) -> int:
        Alice = UnionFind(n)
        Bob = UnionFind(n)
        
        requiredEdges = 0
        for e in edges:
            if e[0] == 3:
                if Alice.Union(e[1], e[2]) and Bob.Union(e[1], e[2]):
                    requiredEdges += 1
                    
        for e in edges:
            if e[0] == 1:
                requiredEdges += Alice.Union(e[1], e[2])
            elif e[0] == 2:
                requiredEdges += Bob.Union(e[1], e[2])
                
        if Alice.is_connected() and Bob.is_connected():
            return len(edges) - requiredEdges
        
        return -1
        