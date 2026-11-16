class Solution:
    def minCost(self, s: str, cost: List[int]) -> int:
        total_cost_dict = defaultdict(int)
        for ch, c in zip(s, cost):
            total_cost_dict[ch] += c

        if len(total_cost_dict) == 1:
            return 0

        return sum(cost) - max(total_cost_dict.values())