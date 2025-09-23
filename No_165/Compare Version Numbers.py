class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        revision_1 = version1.split('.')
        revision_2 = version2.split('.')

        length_diff = len(revision_1) - len(revision_2)
        if length_diff > 0:
            revision_2.extend(['0'] * length_diff)
        elif length_diff < 0:
            revision_1.extend(['0'] * -length_diff)

        for r1, r2 in zip(revision_1, revision_2):
            if int(r1) > int(r2):
                return 1
            elif int(r2) > int(r1):
                return -1
        return 0