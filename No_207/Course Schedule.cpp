class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegree(numCourses);
        unordered_map<int, vector<int>> graph;
        for (int i = 0; i < prerequisites.size(); i++) {
            inDegree[prerequisites[i][1]]++;
            graph[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        
        bool findCourse = true;
        while (findCourse) {
            findCourse = false;
            for (int i = 0; i < numCourses; i++) {
                if (inDegree[i] == 0) {
                    findCourse = true;
                    for (int j = 0; j < graph[i].size(); j++) {
                        inDegree[graph[i][j]]--;
                    }
                    inDegree[i] = -1;
                }
            }
        }
        
        for (int d : inDegree) {
            if (d > 0) return false;
        }
        
        return true;
    }
};