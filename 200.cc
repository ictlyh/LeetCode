class Solution {
  public:
    void islandDFS(int i, int j, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
      int m = grid.size();
      int n = grid[0].size();
      visited[i][j] = true;
      if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == '1') 
        islandDFS(i, j - 1, grid, visited);
      if (j + 1 < n && !visited[i][j + 1] && grid[i][j + 1] == '1')
        islandDFS(i, j + 1, grid, visited);
      if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == '1')
        islandDFS(i - 1, j, grid, visited);
      if (i + 1 < m && !visited[i + 1][j] && grid[i + 1][j] == '1')
        islandDFS(i + 1, j, grid, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
      int m = grid.size();
      if (m == 0) return 0;
      int n = grid[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      int islandCount = 0;
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (!visited[i][j] && grid[i][j] == '1') {
            islandDFS(i, j, grid, visited);
            islandCount++;
          }
        }
      }
      return islandCount;
    }
};
