// 重点掌握使用 stringstream，getline 进行字符串切分
class Solution {
public:
string simplifyPath(string path) {
  if (path.size() < 2) return path;
  stringstream ss(path);
  string str;
  vector<string> paths;
  while (getline(ss, str, '/')) {
    if (str.size() == 0 || str.compare(".") == 0) continue;
    else if (str.compare("..") == 0) {
      if (!paths.empty()) paths.pop_back();
      else continue;
    } else paths.push_back(str);
  }
  string res("");
  for (string path : paths)
    res += "/" + path;
  return res.size() == 0 ? "/" : res;
}
};
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
