class Solution:
    def avoidFlood(self, rains: List[int]) -> List[int]:
        n = len(rains)

        next_rain = [n] * n
        last_seen = {}

        for i in range(n - 1, -1, -1):
            lake = rains[i]
            if lake == 0:
                continue
            if lake in last_seen:
                next_rain[i] = last_seen[lake]
            last_seen[lake] = i

        ans = [-1] * n

        full_lakes = set()
        # min-heap: (next_rain_index, lake)
        urgent_lakes = []

        for day in range(n):
            lake = rains[day]

            if lake > 0:
                if lake in full_lakes:
                    return []

                full_lakes.add(lake)
                heapq.heappush(urgent_lakes, (next_rain[day], lake))
            else:
                if urgent_lakes:
                    _, lake_to_dry = heapq.heappop(urgent_lakes)
                    full_lakes.remove(lake_to_dry)
                    ans[day] = lake_to_dry
                else:
                    ans[day] = 1

        return ans