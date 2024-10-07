class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        
        int dis = 0;
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<vector<int>> visited(m, vector<int>(n, -1));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0, 0}, k});
        
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                auto & [cell, old_k] = q.front();
                auto & [i, j] = cell;
            
                if (i == m - 1 && j == n - 1)
                    return dis;
                
                for (auto & [dr, dc] : directions) {
                    int new_i = i + dr;
                    int new_j = j + dc;
                    if (new_i < 0 || new_i >= m || new_j < 0 || new_j >= n)
                        continue;
                    
                    int new_k = old_k - grid[new_i][new_j];
                    if (new_k < 0)
                        continue;
                    
                    if (visited[new_i][new_j] >= new_k)
                        continue;

                    visited[new_i][new_j] = new_k;
                    q.push({{new_i, new_j}, new_k});
                }
                q.pop();
            }
            dis++;
        }
        
        return -1;
    }
};