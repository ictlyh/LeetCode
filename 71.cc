class Solution {
  public:
    vector<string> splitBySlash(string str) {
      vector<string> res;
      int b = 1;
      int e = str.find_first_of('/', b);
      while (e != -1) {
        string dir = str.substr(b, e - b);
        if (dir.size() != 0)
          res.push_back(str.substr(b, e - b));
        b = e + 1;
        e = str.find_first_of('/', b);
      }
      string dir = str.substr(b);
      if (dir.size() != 0)
        res.push_back(dir);
      return res;
    }

    string simplifyPath(string path) {
      if (path.size() < 2) return path;
      vector<string> dirs = splitBySlash(path);
      stack<string> paths;
      for (int i = 0; i < dirs.size(); i++) {
        if (dirs[i].compare(".") == 0) continue;
        if (dirs[i].compare("..") == 0) {
          if (!paths.empty()) paths.pop();
          else continue;
        } else paths.push(dirs[i]);
      }
      string res("");
      while (!paths.empty()) {
        res.insert(0, "/" + paths.top());
        paths.pop();
      }
      return res.size() == 0 ? "/" : res;
    }
};
