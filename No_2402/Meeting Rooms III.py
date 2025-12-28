class Solution:
    def mostBooked(self, n: int, meetings: list[list[int]]) -> int:
        meetings.sort()

        # [release time, room id]
        room_heap = [[0, i] for i in range(n)]
        heapq.heapify(room_heap)
        
        usage_counts = [0] * n

        for start, end in meetings:
            while room_heap[0][0] < start:
                time, room_id = heapq.heappop(room_heap)
                heapq.heappush(room_heap, [start, room_id])

            release_time, room_id = heapq.heappop(room_heap)
            
            duration = end - start
            heapq.heappush(room_heap, [release_time + duration, room_id])

            usage_counts[room_id] += 1

        return usage_counts.index(max(usage_counts))