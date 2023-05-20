#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void dfs(vector<vector<int>>& image, int i, int j, int c, int color){
        if(i < 0 || i>= image.size() || j < 0 || j >= image[0].size() || image[i][j] == color || image[i][j]!=c)return;
        image[i][j] = color;
    dfs(image, i - 1, j, c, color);
    dfs(image, i + 1, j, c, color);
    dfs(image, i, j - 1, c, color);
    dfs(image, i, j + 1, c, color);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int c = image[sr][sc];
        dfs(image, sr, sc, c, color);
        return image;
    }
};