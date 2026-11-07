Problem Number: 1882. Process Tasks Using Servers

Difficulty: `Medium`

## Problem Description

You are given two **0-indexed** integer arrays `servers` and `tasks` of lengths `n` and `m` respectively. `servers[i]` is the **weight** of the $i^{\text{th}}$ server, and `tasks[j]` is the **time needed** to process the $j^{\text{th}}$ task **in seconds**.

Tasks are assigned to the servers using a **task queue**. Initially, all servers are free, and the queue is **empty**.

At second `j`, the $j^{\text{th}}$ task is **inserted** into the queue (starting with the $0^{\text{th}}$ task being inserted at second `0`). As long as there are free servers and the queue is not empty, the task in the front of the queue will be assigned to a free server with the **smallest weight**, and in case of a tie, it is assigned to a free server with the **smallest index**.

If there are no free servers and the queue is not empty, we wait until a server becomes free and immediately assign the next task. If multiple servers become free at the same time, then multiple tasks from the queue will be assigned **in order of insertion** following the weight and index priorities above.

A server that is assigned task `j` at second `t` will be free again at second `t + tasks[j]`.

Build an array `ans` of length `m`, where `ans[j]` is the **index** of the server the $j^{\text{th}}$ task will be assigned to.

Return *the array* `ans`.

**Example 1:**
```
Input: servers = [3,3,2], tasks = [1,2,3,2,1,2]
Output: [2,2,0,2,1,2]
Explanation: Events in chronological order go as follows:
- At second 0, task 0 is added and processed using server 2 until second 1.
- At second 1, server 2 becomes free. Task 1 is added and processed using server 2 until second 3.
- At second 2, task 2 is added and processed using server 0 until second 5.
- At second 3, server 2 becomes free. Task 3 is added and processed using server 2 until second 5.
- At second 4, task 4 is added and processed using server 1 until second 5.
- At second 5, all servers become free. Task 5 is added and processed using server 2 until second 7.
```
**Constraints:**

- `servers.length == n`
- `tasks.length == m`
- `1 <= n, m <= 2 * 10^5`
- `1 <= servers[i], tasks[j] <= 2 * 10^5`

**Intuition:**

### Solution Intuition

We maintain two min-heaps to handle server availability and scheduling:

- `free_servers`: [weight, index] — Priority queue for idle servers. Python automatically breaks ties by index.

- `processing_servers`: [free_time, weight, index] — Sorted by free_time so we can quickly find which server finishes next.

Detailed Logic & `current_time` Updates:

1. **Arrival Time Alignment (`max(current_time, task_idx)`)** 
   Task `task_idx` arrives at second `task_idx`. If previous tasks finished quickly, `current_time` might lag behind. `max()` advances time to the task's arrival without rewinding time when tasks are backlogged.

2. **Releasing Finished Servers (`release_servers()`)** 
   Pops servers from `processing_servers` whose `free_time <= current_time` and pushes them back into `free_servers`.

3. **Fast-Forwarding Time (`if not free_servers`)** 
   If all servers are busy, we avoid checking second-by-second. Instead, we jump `current_time` directly to `processing_servers[0][0]` (the earliest completion time) and run `release_servers()` immediately.

4. **Task Assignment** 
   Pops the optimal server from `free_servers`, records its `index`, and pushes it into `processing_servers` with its updated completion time (`current_time + task_duration`).