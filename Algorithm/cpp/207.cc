class Solution {
  public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<int> indegree(numCourses, 0);
      vector<int> visited(numCourses, false);
      int visitedCount = 0;
      for (pair<int, int> prerequisite : prerequisites)
        indegree[prerequisite.first]++;
      while (visitedCount < numCourses) {
        int i = 0;
        for (; i < numCourses; i++) {
          if (!visited[i] && indegree[i] == 0) {
            visitedCount++;
            if (visitedCount == numCourses)
              return true;
            visited[i] = true;
            for (pair<int, int> prerequisite : prerequisites) {
              if (prerequisite.second == i)
                indegree[prerequisite.first]--;
            }
            break;
          }
        }
        if (i == numCourses) break;
      }
      return false;
    }
};
