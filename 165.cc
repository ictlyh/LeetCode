class Solution {
  public:
    vector<string> split(string str) {
      vector<string> res;
      int b = 0;
      int e = str.find_first_of('.');
      while (e != -1) {
        res.push_back(str.substr(b, e - b));
        b = e + 1;
        e = str.find_first_of('.', b);
      }
      res.push_back(str.substr(b));
      return res;
    }

    int compareVersion(string version1, string version2) {
      vector<string> ver1 = split(version1);
      vector<string> ver2 = split(version2);
      int i = 0;
      for (; i < ver1.size() && i < ver2.size(); i++) {
        int v1 = atoi(ver1[i].c_str());
        int v2 = atoi(ver2[i].c_str());
        if (v1 < v2) return -1;
        else if (v1 > v2) return 1;
      }
      if (i < ver1.size()) {
        for (; i < ver1.size(); i++)
          if (atoi(ver1[i].c_str()) != 0) return 1;
      }
      if (i < ver2.size()) {
        for (; i < ver2.size(); i++)
          if (atoi(ver2[i].c_str()) != 0) return -1;
      }
      return 0;
    }
};
