class Solution:
    def watchedVideosByFriends(self, watchedVideos: List[List[str]], friends: List[List[int]], id: int, level: int) -> List[str]:
        visited = {id}
        queue = deque([id])

        for _ in range(level):
            for _ in range(len(queue)):
                person = queue.popleft()
                for f in friends[person]:
                    if f not in visited:
                        visited.add(f)
                        queue.append(f)

        counter = Counter()
        for friend_id in queue:
            counter.update(watchedVideos[friend_id])

        return sorted(counter.keys(), key=lambda x: (counter[x], x))
