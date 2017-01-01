class Solution {
  public:
    void islandDFS(int i, int j, vector<vector<char>>& grid) {
      int m = grid.size();
      int n = grid[0].size();
      grid[i][j] = '0';
      if (j - 1 >= 0 && grid[i][j - 1] == '1') 
        islandDFS(i, j - 1, grid);
      if (j + 1 < n && grid[i][j + 1] == '1')
        islandDFS(i, j + 1, grid);
      if (i - 1 >= 0 && grid[i - 1][j] == '1')
        islandDFS(i - 1, j, grid);
      if (i + 1 < m && grid[i + 1][j] == '1')
        islandDFS(i + 1, j, grid);
    }

    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      if (m == 0) return 0;
      int n = grid[0].size();
      int islandCount = 0;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (grid[i][j] == '1') {
            islandDFS(i, j, grid);
            islandCount++;
          }
        }
      }
      return islandCount;
    }
};
