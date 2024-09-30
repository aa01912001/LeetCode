class Solution:
    def eventualSafeNodes(self, graph: List[List[int]]) -> List[int]:
        def DFS(graph, color, n) -> bool:
            if color[n] == 1:
                return True
            if color[n] == 2:
                return False
            
            color[n] = 2
            for i in graph[n]:
                if not DFS(graph, color, i):
                    return False
            
            color[n] = 1
            return True
            
        n = len(graph)
        ret = []
        color = [0] * n #  0: not visited, 1: safe, 2: unsafe
        for i in range(n):
            if DFS(graph, color, i):
                ret.append(i)
            
        return ret