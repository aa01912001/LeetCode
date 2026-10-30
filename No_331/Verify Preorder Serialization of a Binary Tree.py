class Solution:
    def isValidSerialization(self, preorder: str) -> bool:
        score = 0
        for c in preorder.split(','):
            if score == -1:
                return False

            score += 1 if c != '#' else -1

            if score < -1:
                return False

        return True if score == -1 else False