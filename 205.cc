class Solution {
  public:
    bool hasMapped(map<char, char>& mymap, char t) {
      map<char, char>::iterator ite = mymap.begin();
      while (ite != mymap.end()) {
        if (ite->second == t) return true;
        ite++;
      }
      return false;
    }

    bool isIsomorphic(string s, string t) {
      map<char, char> mymap;
      for (int i = 0; i < s.length(); i++) {
        map<char, char>::iterator ite = mymap.find(s[i]);
        if (ite != mymap.end()) {
          if (ite->second != t[i]) return false;
        } else if (hasMapped(mymap, t[i])) return false;
        else mymap.insert(pair<char, char>(s[i], t[i]));
      }
      return true;
    }
};

class Solution {
  public:
    bool isIsomorphic(string s, string t) {
      int s_map[128]{0}, t_map[128]{0};
      int i = 0;
      while(i < s.length())
      {
        if(s_map[s[i]]) { if(s_map[s[i]] != t[i]) return false; }
        else if(t_map[t[i]]) { if(t_map[t[i]] != s[i]) return false; }
        else s_map[s[i]] = t[i], t_map[t[i]] = s[i];
        i++;
      }
      return true;
    }
};
