class Solution:
    def assignTasks(self, servers: list[int], tasks: list[int]) -> list[int]:
        # Free server heap: stores [weight, index]
        free_servers = [[weight, i] for i, weight in enumerate(servers)]
        heapq.heapify(free_servers)
        
        # Processing server heap: stores [free_time, weight, index]
        processing_servers = []
        
        ans = []
        current_time = 0
        
        # Helper function to release servers that have finished their tasks by current_time
        def release_servers():
            while processing_servers and processing_servers[0][0] <= current_time:
                _, weight, server_idx = heapq.heappop(processing_servers)
                heapq.heappush(free_servers, [weight, server_idx])
        
        for task_idx, task_duration in enumerate(tasks):
            current_time = max(current_time, task_idx)
            
            # Release finished servers
            release_servers()
            
            # If no free servers are available, fast-forward time and release again
            if not free_servers:
                current_time = processing_servers[0][0]
                release_servers()
            
            # Assign the task to the idle server with the smallest weight (and smallest index on tie)
            weight, server_idx = heapq.heappop(free_servers)
            ans.append(server_idx)
            heapq.heappush(processing_servers, [current_time + task_duration, weight, server_idx])
            
        return ans