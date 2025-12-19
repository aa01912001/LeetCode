class Solution:
    def _find_parent(self, parents, i):
        root = i
        while parents[root] >= 0:
            root = parents[root]

        curr = i
        while parents[curr] >= 0:
            next_node = parents[curr]
            parents[curr] = root
            curr = next_node
        return root

    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        parents = [-1] * n
        # -2 means that this person has secret
        parents[0] = -2 
        parents[firstPerson] = -2

        meetings.sort(key=lambda x: x[2])
        
        m = len(meetings)
        i = 0
        while i < m:
            curr_time = meetings[i][2]
            attendees = set()
            
            j = i
            while j < m and meetings[j][2] == curr_time:
                u, v = meetings[j][0], meetings[j][1]
                attendees.add(u)
                attendees.add(v)
                
                root_u = self._find_parent(parents, u)
                root_v = self._find_parent(parents, v)
                
                if root_u != root_v:
                    if parents[root_u] == -2:
                        parents[root_v] = root_u
                    elif parents[root_v] == -2:
                        parents[root_u] = root_v
                    else:
                        parents[root_v] = root_u
                j += 1
            
            for p in attendees:
                if parents[self._find_parent(parents, p)] != -2:
                    parents[p] = -1 
            
            i = j

        ans = []
        for i in range(n):
            if parents[self._find_parent(parents, i)] == -2:
                ans.append(i)
        return ans