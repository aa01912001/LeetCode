class Solution:
	def findSubtreeSizes(self, parent: List[int], s: str) -> List[int]:
		n = len(s)
		orig_tree = defaultdict(list)
		for node in range(1, n):
			orig_tree[parent[node]].append(node)

		new_parent = parent[:]
		closest_ancestor = {}

		def reassign_parents(node: int) -> None:
			label = s[node]
			prev_ancestor = closest_ancestor.get(label, -1)

			# Reassign parent to the closest ancestor with the same character if one exists
			if prev_ancestor != -1:
				new_parent[node] = prev_ancestor

			# Temporarily set current node as the closest ancestor for its subtree
			closest_ancestor[label] = node

			for child in orig_tree[node]:
				reassign_parents(child)

			if prev_ancestor == -1:
				del closest_ancestor[label]
			else:
				closest_ancestor[label] = prev_ancestor

		reassign_parents(0)

		# Build the final tree using updated parent pointers
		final_tree = defaultdict(list)
		for node in range(1, n):
			final_tree[new_parent[node]].append(node)

		ans = [1] * n

		def calc_subtree_size(node: int) -> int:
			size = 1
			for child in final_tree[node]:
				size += calc_subtree_size(child)
			ans[node] = size
			return size

		calc_subtree_size(0)
		return ans