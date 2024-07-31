class Solution:
    def pathInZigZagTree(self, label: int) -> List[int]:
        h = int(log(label)/log(2))
        
        path = [label];
        while h != 0:
            parent = pow(2, h-1) + (pow(2, h) - 1 - int(path[-1] / 2))
            path.append(parent)
            h -= 1
        
        return path[::-1]