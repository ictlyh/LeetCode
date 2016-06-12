class Solution {
  public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
      vector<int> indegree(numCourses, 0);
      vector<int> visited(numCourses, false);
      for (pair<int, int> prerequisite : prerequisites)
        indegree[prerequisite.first]++;
      vector<int> res;
      while (res.size() < numCourses) {
        int i = 0;
        for (; i < numCourses; i++) {
          if (!visited[i] && indegree[i] == 0) {
            res.push_back(i);
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
      return res.size() == numCourses ? res : vector<int>();
    }
};
