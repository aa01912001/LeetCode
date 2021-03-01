class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        DFS(rooms, visited, 0);
        
        for(int i=0; i< visited.size(); i++) {
            if(visited[i] == false) return false;
        }
        
        return true;
    }
    
    void DFS(vector<vector<int>>& rooms, vector<bool>& visited, int room) {
        visited[room] = true;
        if(rooms[room].size() == 0) return;
        for(int i=0; i<rooms[room].size(); i++) {
            if(visited[rooms[room][i]] == true) continue;
            DFS(rooms, visited, rooms[room][i]);
        }
        
        return;
    }
};