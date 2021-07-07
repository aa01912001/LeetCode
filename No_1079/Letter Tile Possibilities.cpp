class Solution {
private:
    unordered_set<string> hset;
public:
    int numTilePossibilities(string tiles) {
        permutation(tiles, 0);
        return hset.size();
    }
    
    void permutation(string tiles, int i) {
        if(i == tiles.size()-1) {
            hset.insert(tiles.substr(0,i+1));
            return;
        }
        
        for(int j=i; j<tiles.size(); j++) {
            swap(tiles, i, j);
            hset.insert(tiles.substr(0,i+1));
            permutation(tiles, i+1);
            swap(tiles, i, j);
        }
        
        return;
    }
    
    void swap(string& tiles, int i, int j) {
        char t = tiles[i];
        tiles[i] = tiles[j];
        tiles[j] = t;
        return;
    }
};