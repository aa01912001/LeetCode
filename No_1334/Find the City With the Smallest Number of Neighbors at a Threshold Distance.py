class Solution:
    def findTheCity(self, n: int, edges: List[List[int]], distanceThreshold: int) -> int:
        dis = [[float('inf')] * n for _ in range(n)]
        
        for i, j, w in edges:
            dis[i][j] = dis[j][i] = w
            
        for i in range(n):
            dis[i][i] = 0
            
        for k in range(n):
            for i in range(n):
                for j in range(n):
                    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j])
        
        ret = -1
        min_num_of_cities = float('inf')
        for i in reversed(range(n)):
            total = sum(1 for d in dis[i] if d <= distanceThreshold)
            if total < min_num_of_cities:
                ret = i
                min_num_of_cities = total
                
        return ret
        
        