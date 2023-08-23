class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        sort(tiles.begin(), tiles.end());
        int ret = 0, left = 0, coveredTiles = 0, n = tiles.size(), i = 0;
        while (ret < carpetLen && i < n) {
            if (tiles[left][0] + carpetLen > tiles[i][1]) {
                coveredTiles += tiles[i][1] - tiles[i][0] + 1;
                ret = max(ret, coveredTiles);
                i++;
            } else {
                ret = max(ret, coveredTiles + max(0, tiles[left][0]+carpetLen-tiles[i][0]));
                coveredTiles -= (tiles[left][1] - tiles[left][0] + 1);
                left++;
            }
        }
        
        return ret;
    }
};