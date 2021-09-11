class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        int m = image.size();
        int n = image[0].size();
        
        if(image[sr][sc] == newColor) return image; // avoid loop
        image[sr][sc] = newColor;
        
        if(sr-1 >= 0 && image[sr-1][sc] == oldColor) floodFill(image, sr-1, sc, newColor);
        if(sr+1 < m && image[sr+1][sc] == oldColor) floodFill(image, sr+1, sc, newColor);
        if(sc-1 >= 0 && image[sr][sc-1] == oldColor) floodFill(image, sr, sc-1, newColor);
        if(sc+1 < n && image[sr][sc+1] == oldColor) floodFill(image, sr, sc+1, newColor);
        
        return image;
    }
    
};