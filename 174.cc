class Solution {
  public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
      int m = dungeon.size();
      if (m == 0) return 1;
      int n = dungeon[0].size();
      if (n == 0) return 1;
      for (int i = 0; i < m - 1; i++)
        dungeon[i].push_back(INT_MAX);
      dungeon.back().push_back(1);
      dungeon.push_back(vector<int>(n - 1, INT_MAX));
      dungeon.back().push_back(1);
      for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
          int hp = min(dungeon[i][j + 1], dungeon[i + 1][j]) - dungeon[i][j];
          dungeon[i][j] = hp <= 0 ? 1 : hp;
        }
      }
      return dungeon[0][0];
    }
};
