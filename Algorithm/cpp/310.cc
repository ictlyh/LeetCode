



// Time Limit Exceeded
class Solution {
  public:
    int findMinHeightTree(int n, int root, vector<pair<int, int>>& edges) {
      vector<bool> visited(n, false);
      queue<int> myqueue;
      myqueue.push(root);
      myqueue.push(-1);
      int depth = 0;
      while (!myqueue.empty()) {
        int node = myqueue.front();
        myqueue.pop();
        if (node == -1) {
          depth++;
          if (myqueue.empty()) break;
          myqueue.push(-1);
        } else {
          visited[node] = true;
          for (pair<int, int> edge : edges) {
            if (edge.first == node && !visited[edge.second])
              myqueue.push(edge.second);
            else if (edge.second == node && !visited[edge.first])
              myqueue.push(edge.first);
          }
        }
      }
      return depth;
    }

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
      vector<int> res;
      int mindepth = INT_MAX;
      for (int i = 0; i < n; i++) {
        int tmp = findMinHeightTree(n, i, edges);
        if (tmp < mindepth) {
          res.clear();
          res.push_back(i);
          mindepth = tmp;
        } else if (tmp == mindepth) {
          res.push_back(i);
        }
      }
      return res;
    }
};
